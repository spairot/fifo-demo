/*
 * ring_buffer.h
 *
 * Created: 14/03/2017 10:07:45
 *  Author: Jonathan
 */ 


#ifndef RING_BUFFER_H_
#define RING_BUFFER_H_

#define RING_BUFFER_SIZE	100

typedef struct
{
	unsigned char head;
	unsigned char tail;
	unsigned char data[RING_BUFFER_SIZE];
}ring_buffer_t;


void			RB_init(ring_buffer_t *rb);
unsigned char	RB_free(ring_buffer_t *rb);
unsigned char	RB_length(ring_buffer_t *rb);
unsigned char	RB_readByte(ring_buffer_t *rb);
unsigned char	RB_writeByte(ring_buffer_t *rb, unsigned char data);
unsigned char	RB_read(ring_buffer_t *rb, unsigned char *data, unsigned char datal);
unsigned char	RB_write(ring_buffer_t *rb, unsigned char *data, unsigned char datal);


#endif /* RING_BUFFER_H_ */