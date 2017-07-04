/* 
 * Copyright (c) 2003 NONAKA Kimihiro
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include	"windows.h"
#include	"common.h"
#include	"dswin.h"
#include	"prop.h"
#include	"adpcm.h"
#include	"mercury.h"
#include	"fmg_wrap.h"

#include "libretro.h"
extern retro_audio_sample_batch_t audio_batch_cb;
extern signed short soundbuf[1024*2];

short	playing = FALSE;

#define PCMBUF_SIZE 2*2*48000
BYTE pcmbuffer[PCMBUF_SIZE];
BYTE *pcmbufp = pcmbuffer;
BYTE *pbsp = pcmbuffer;
BYTE *pbrp = pcmbuffer, *pbwp = pcmbuffer;
BYTE *pbep = &pcmbuffer[PCMBUF_SIZE];
DWORD ratebase = 22050;
long DSound_PreCounter = 0;
BYTE rsndbuf[PCMBUF_SIZE];

int audio_fd = 1;

void raudio_callback(void *userdata, unsigned char *stream, int len);

#ifndef NOSOUND

int
DSound_Init(unsigned long rate, unsigned long buflen)
{
	DWORD samples;

	if (playing)
		return FALSE;

	if (rate == 0)
   {
		audio_fd = -1;
		return TRUE;
	}

	ratebase = rate;

	samples = 2048;

	playing = TRUE;
	return TRUE;
}

void
DSound_Play(void)
{
   	if (audio_fd >= 0) {
		ADPCM_SetVolume((BYTE)Config.PCM_VOL);
		OPM_SetVolume((BYTE)Config.OPM_VOL);	
	}
}

void
DSound_Stop(void)
{
   	if (audio_fd >= 0) {
		ADPCM_SetVolume(0);
		OPM_SetVolume(0);	
	}
}

int
DSound_Cleanup(void)
{
	playing = FALSE;

	if (audio_fd >= 0)
		audio_fd = -1;

	return TRUE;
}

static void sound_send(int length)
{
   int rate = 0;

   ADPCM_Update((short *)pbwp, length, rate, pbsp, pbep);
   OPM_Update((short *)pbwp, length, rate, pbsp, pbep);
#ifndef	NO_MERCURY
   //Mcry_Update((short *)pcmbufp, length);
#endif

   pbwp += length * sizeof(WORD) * 2;
   if (pbwp >= pbep)
      pbwp = pbsp + (pbwp - pbep);
}

void FASTCALL DSound_Send0(long clock)
{
	int length = 0;
	int rate;

	if (audio_fd < 0)
		return;

	DSound_PreCounter += (ratebase * clock);

	while (DSound_PreCounter >= 10000000L)
   {
		length++;
		DSound_PreCounter -= 10000000L;
	}

	if (length == 0)
		return;

	sound_send(length);
}

static void FASTCALL DSound_Send(int length)
{
	int rate;

	if (audio_fd < 0)
		return;
	sound_send(length);
}

void
raudio_callback(void *userdata, unsigned char *stream, int len)
{
   int lena, lenb, datalen, rate;
   BYTE *buf;

cb_start:
   if (pbrp <= pbwp)
   {
      // pcmbuffer
      // +---------+-------------+----------+
      // |         |/////////////|          |
      // +---------+-------------+----------+
      // A         A<--datalen-->A          A
      // |         |             |          |
      // pbsp     pbrp          pbwp       pbep

      datalen = pbwp - pbrp;

      // needs more data
      if (datalen < len)
         DSound_Send((len - datalen) / 4);

#if 0
      datalen = pbwp - pbrp;
      if (datalen < len)
         printf("xxxxx not enough sound data xxxxx\n");
#endif

      // change to TYPEC or TYPED
      if (pbrp > pbwp)
         goto cb_start;

      buf = pbrp;
      pbrp += len;
      //printf("TYPEA: ");
   }
   else
   {
      // pcmbuffer
      // +---------+-------------+----------+
      // |/////////|             |//////////|
      // +------+--+-------------+----------+
      // <-lenb->  A             <---lena--->
      // A         |             A          A
      // |         |             |          |
      // pbsp     pbwp          pbrp       pbep

      lena = pbep - pbrp;
      if (lena >= len)
      {
         buf = pbrp;
         pbrp += len;
         //printf("TYPEC: ");
      }
      else
      {
         lenb = len - lena;

         if (pbwp - pbsp < lenb)
            DSound_Send((lenb - (pbwp - pbsp)) / 4);

#if 0
         if (pbwp - pbsp < lenb)
            printf("xxxxx not enough sound data xxxxx\n");
#endif
         memcpy(rsndbuf, pbrp, lena);
         memcpy(&rsndbuf[lena], pbsp, lenb);
         buf = rsndbuf;
         pbrp = pbsp + lenb;
         //printf("TYPED: ");
      }
   }

   signed short int *ptr=(signed short int *)buf;
   memcpy(&soundbuf[0],buf,len);
   audio_batch_cb(soundbuf,len/4);

}

#else	/* NOSOUND */
int
DSound_Init(unsigned long rate, unsigned long buflen)
{
	return FALSE;
}

void
DSound_Play(void)
{
}

void
DSound_Stop(void)
{
}

int
DSound_Cleanup(void)
{
	return TRUE;
}

void FASTCALL
DSound_Send0(long clock)
{
}
#endif	/* !NOSOUND */
