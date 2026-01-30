# Simple Router Test

A software-defined networking (SDN) project combining a simple router implementation with a POX controller for managing network routing and topology.

## Overview

This project demonstrates a simple router implementation with OpenFlow switch control. It includes:
- A custom router implementation (C/C++)
- Mininet-based network topology simulation
- POX controller integration for OpenFlow management
- Network configuration and routing table setup

## Directory Structure

### Core Components
- **router/** - Router implementation
  - `sr_*.c/h` - Core router functionality (ARP cache, routing table, VNS communication)
  - `Makefile` - Build configuration
  - `rtable` - Routing table configuration
  - `ping.sh`, `traceroute.sh` - Network testing scripts

- **pox/** - POX OpenFlow controller framework
  - **controllers/** - Controller implementations
  - **forwarding/** - Forwarding logic (L2/L3 learning switches)
  - **openflow/** - OpenFlow protocol implementation
  - **lib/** - Utility libraries
  - **topology/** - Network topology management

- **pox_module/** - Custom POX module extensions

### Configuration & Testing
- **topo.py** - Mininet topology definition (server1, server2, client, router)
- **IP_CONFIG** - IP address configuration
- **rtable** - Routing table entries
- **http_server1/**, **http_server2/** - Web server instances

## Building & Running

### Build Router
```bash
cd router
make
```

### Network Testing
```bash
./router/ping.sh <ip_address>
./router/traceroute.sh <ip_address>
```

## Key Features

- OpenFlow-based switch control
- Simple IP routing with ARP cache
- Network topology simulation via Mininet
- Distributed routing table management
- VNS (Virtual Network System) communication protocol support

## Files

- `auth_key` - Authentication credentials
- `IP_CONFIG` - Network interface IP configuration
- `rtable` - Static routing table
