/*****************************************/
/*      define 802.11 parameters         */
/****************************************/
#ifndef _802_11_h
#define _802_11_h

/* select one */
//#define IEEE802_11g
#define IEEE802_11b
//#define IEEE802_11a


#define PAYLOAD_BYTE 1500.0
#define PAYLOAD_BIT (1500.0*8.0)

#if defined IEEE802_11b

#define CWmin 31
#define CWmax 1023
#define RATE 11.0 //Mbps
#define DIFS 50.0 //micro sec
#define SIFS 10.0 //
#define SLOT 20.0
#define HEADERS (144.0 + 48.0)
#define DATA_SIZE (24.0 + 8.0 + PAYLOAD_BYTE + 4.0)*8.0  //bit
#define ACK_SIZE 14.0 * 8.0 //bit

#elif defined IEEE802_11a

#define CWmin 15
#define CWmax 1023
#define RATE 54.0 //Mbps
#define DIFS 34.0 //micro sec
#define SIFS 16.0 //
#define SLOT 9.0 //
#define HEADERS (16.0 + 4.0)
#define DATA_SIZE (16.0 + 24*8.0 + 8.0*8.0 + PAYLOAD_BIT + 4.0*8.0 +6.0)  //bit
#define ACK_SIZE  (16.0 + 14*8.0 + 6.0)//bit

#elif defined IEEE802_11g

#define CWmin 15
#define CWmax 1023
#define RATE 54.0 //Mbps
#define DIFS 50.0 //micro sec
#define SIFS 10.0 //
#define SLOT 20.0 //
#define HEADERS (16.0 + 4.0)
#define DATA_SIZE (16.0 + 24*8.0 + 8.0*8.0 + PAYLOAD_BIT + 4.0*8.0 +6.0)  //bit
#define ACK_SIZE  (16.0 + 14*8.0 + 6.0)//bit

#endif

#define I_TIME SLOT //micro sec
#define S_TIME  (HEADERS + DATA_SIZE/RATE + SIFS + HEADERS + ACK_SIZE/RATE + DIFS) //micro sec
#define C_TIME  (HEADERS + DATA_SIZE/RATE + DIFS) //micro sec

#endif
