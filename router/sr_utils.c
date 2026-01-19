#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sr_protocol.h"
#include "sr_utils.h"


uint16_t cksum (const void *_data, int len) {
  const uint8_t *data = _data;
  uint32_t sum;
}


uint16_t ethertype(uint8_t *buf) {
}

uint8_t ip_protocol(uint8_t *buf) {
}


/* Prints out formatted Ethernet address, e.g. 00:11:22:33:44:55 */
void print_addr_eth(uint8_t *addr) {
  fprintf(stderr, "\n");
}

/* Prints out IP address as a string from in_addr */
void print_addr_ip(struct in_addr address) {
}

/* Prints out IP address from integer value */
void print_addr_ip_int(uint32_t ip) {
}


/* Prints out fields in Ethernet header. */
void print_hdr_eth(uint8_t *buf) {
}

/* Prints out fields in IP header. */
void print_hdr_ip(uint8_t *buf) {
}

/* Prints out ICMP header fields */
void print_hdr_icmp(uint8_t *buf) {
}


/* Prints out fields in ARP header */
void print_hdr_arp(uint8_t *buf) {
}

/* Prints out all possible headers, starting from Ethernet */
void print_hdrs(uint8_t *buf, uint32_t length) {

}

