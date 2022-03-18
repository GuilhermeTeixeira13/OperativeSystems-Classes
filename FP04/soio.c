/*
 *  soio.c
 *
 *  Created by Paul Crocker on 3/11/07.
 *  Copyright 2007 UBI. All rights reserved.
 *
 */
#include "soio.h"

SOFILE *sofopen (const char *nome, const char *mode)
{
  SOFILE *novo = NULL;
  int fd;

  if (mode[0] == 'r')
    fd = open (nome, O_RDONLY, 0);
  else
    exit (1);			//agora apenas para leitura !

  if (-1 == fd)
    return NULL;		//caso erro

  char fdc ='0'+fd;  //ok if fd<=9
  write(2,"FD ",3); write(2,&fdc,1);  write(2,"\n",1);

  novo = (SOFILE *) malloc (sizeof (SOFILE));
  novo->buf = (char *) malloc (MAXBUFFSIZE);
  novo->fd = fd;
  novo->index = 0;
  novo->size = 0;
  return novo;
}

int sofclose (SOFILE * fp)
{
  if(fp != NULL){
    if (close(fp->fd) == -1) {
      return -1;  
    }
    free(fp->buf);
    free(fp);
  }
  return 0;
}

int sofgetc (SOFILE * fp)
{				
  char letra;

  fp->size = read(fp->fd, &letra, sizeof(char));
  if (fp->size == -1) {
    return -1;
  }
  else if(fp->size == fp->index || fp->size == 0){
    return EOF;
  }
  else{
    fp->buf[fp->index] = letra;
    fp->index++;
    if(fp->size == fp->index || fp->size == 0){
      fp->index = 0;
      fp->size = 0;
    }
    return letra;
  }

  return letra;
}

int sofflush (SOFILE * fp)
{
  write(1, fp->buf, fp->size);

  return 0;
}

