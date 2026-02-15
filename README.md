# Simple Router Network Simulator

<!-- LOGO placeholder: Consider adding a network topology diagram or project icon here -->
[![Live Demo](https://img.shields.io/badge/Demo-Live_Preview-0078D4?logo=google-chrome&logoColor=white)](http://simplerouter-simplerouter-cvoi4f-bbc805-72-61-1-6.traefik.me)
![License](https://img.shields.io/badge/license-MIT-blue.svg)
![Language](https://img.shields.io/badge/language-C%20|%20Python-orange.svg)
![Docker](https://img.shields.io/badge/docker-ready-brightgreen.svg)
![Mininet](https://img.shields.io/badge/mininet-compatible-blue.svg)

**A comprehensive, containerized network router implementation with web-based interactive topology management and automated testing.**

This project provides an educational, full-featured network router simulation environment combining low-level C-based routing logic, OpenFlow SDN control, Mininet network emulation, and a modern web interface for real-time network interaction and visualization.

![Project Screenshot](Screenshot.png)
<!-- Screenshot Suggestion: Capture the web interface showing the Mininet CLI terminal with network topology visualization or test results -->

---

## Table of Contents

- [About The Project](#about-the-project)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
  - [Running with Docker Compose](#running-with-docker-compose)
  - [Accessing the Web Interface](#accessing-the-web-interface)
  - [CLI Usage](#cli-usage)
  - [Configuration](#configuration)
- [Roadmap](#roadmap)
- [License](#license)
- [Contact / Support](#contact--support)

---

## About The Project

### Motivation

Building network routers from scratch is essential for understanding how the internet works at a fundamental level. This project was created to provide hands-on experience with:
- **IP routing and forwarding** with longest prefix matching algorithms
- **ARP (Address Resolution Protocol)** cache management
- **ICMP (Internet Control Message Protocol)** error handling and diagnostics
- **OpenFlow SDN controller** integration for programmable network control
- **Network topology simulation** using Mininet for realistic testing environments

Instead of just theoretical knowledge, this project allows you to run, test, and visualize actual network packet flows in a controlled, reproducible environment—all inside a Docker container.

### Key Features

✅ **Custom C-based Router Implementation**
- Full IP packet forwarding with routing table lookups
- ARP cache with request/reply handling
- ICMP echo (ping) replies and error messages (TTL exceeded, port/net unreachable)
- Longest prefix matching for route selection

✅ **POX OpenFlow Controller Integration**
- Software-Defined Networking (SDN) control plane
- Custom OpenFlow handlers for dynamic packet processing
- Remote controller architecture for centralized network management

✅ **Mininet Network Topology**
- 3-host network (client, server1, server2) connected via OpenFlow switch
- Configurable IP addressing and routing tables
- Realistic network emulation with isolated namespaces

✅ **Web-Based Interactive Terminal**
- Flask + SocketIO real-time web interface
- Full Mininet CLI access via browser using Xterm.js-style PTY streaming
- No SSH or local terminal required—interact with the network from any browser

✅ **Comprehensive Automated Testing**
- 11 test cases covering ARP, ICMP, routing, traceroute, and HTTP
- Automated grading system with JSON results output
- Individual test case execution support

✅ **Fully Dockerized**
- One-command deployment with Docker Compose
- Privileged mode for Mininet network namespace creation
- Pre-built router binary included in the container

### Built With

**Core Technologies:**

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Python](https://img.shields.io/badge/Python_2/3-3776AB?style=for-the-badge&logo=python&logoColor=white)
![Flask](https://img.shields.io/badge/Flask-000000?style=for-the-badge&logo=flask&logoColor=white)
![Docker](https://img.shields.io/badge/Docker-2496ED?style=for-the-badge&logo=docker&logoColor=white)

**Key Libraries & Frameworks:**
- **Mininet** - Network emulation platform
- **POX** - Python-based OpenFlow controller framework
- **Flask-SocketIO** - Real-time WebSocket communication
- **Eventlet** - Concurrent networking library for Python
- **GCC** - GNU C Compiler for router binary compilation

---

## Getting Started

### Prerequisites

Ensure you have the following installed on your system:

- **Docker** (version 20.10 or higher)
  ```bash
  docker --version
  ```

- **Docker Compose** (version 1.29 or higher)
  ```bash
  docker-compose --version
  ```

> **Note:** This project requires Docker to run in **privileged mode** because Mininet needs to create network namespaces. Ensure your Docker environment supports this.

### Installation

1. **Clone the repository**
   ```bash
   git clone https://github.com/jason-n-tran/simple_router.git
   cd simple_router
   ```

2. **Build the Docker image**
   ```bash
   docker-compose build
   ```
   
   This will:
   - Install Mininet, Open vSwitch, Python 2/3, and all dependencies
   - Compile the C-based router from source
   - Install Flask web application dependencies
   - Configure the entrypoint script

3. **Verify the build**
   ```bash
   docker images | grep simple_router
   ```

---

## Usage

### Running with Docker Compose

Start the entire network simulation environment with a single command:

```bash
docker-compose up
```

**What happens during startup:**
1. OpenVSwitch service initializes
2. POX OpenFlow controller starts on port 6633
3. Mininet topology is created with 3 hosts and 1 OpenFlow switch
4. Simple Router binary connects to the controller
5. Flask web server starts on port 8070

You should see output like:
```
*** Creating network
*** Adding controller
*** Starting SimpleHTTPServer on host server1
*** Starting SimpleHTTPServer on host server2
*** Starting Web Interface on port 8070...
```

### Accessing the Web Interface

Once the container is running, open your browser and navigate to:

```
http://localhost:8070
```

You'll see an interactive terminal connected to the Mininet CLI. From here, you can:

- **Run ping tests:**
  ```
  mininet> client ping -c 3 192.168.2.2
  ```

- **Test HTTP servers:**
  ```
  mininet> client wget http://192.168.2.2
  ```

- **Run traceroute:**
  ```
  mininet> client traceroute 172.64.3.10
  ```

- **Check ARP table:**
  ```
  mininet> client arp -n
  ```

### CLI Usage

If you prefer direct terminal access, you can execute commands inside the container:

```bash
# Attach to running container
docker exec -it simple_router_demo bash

# Run a specific test case
python2 testcases.py -t 1

# Run all test cases
python2 testcases.py

# Build router manually
cd router && make clean && make

# View routing table
cat rtable
```

### Configuration

![Configuration](topo.png)

#### IP Address Configuration (`IP_CONFIG`)

Edit this file to change host and interface IP addresses:

```
server1 192.168.2.2
server2 172.64.3.10
client  10.0.1.100
sw0-eth1 192.168.2.1
sw0-eth2 172.64.3.1
sw0-eth3 10.0.1.1
```

#### Routing Table (`rtable`)

Define static routes for the router:

```
# Destination    Gateway         Subnet Mask      Interface
10.0.1.100       10.0.1.100      255.255.255.255  eth3
192.168.2.2      192.168.2.2     255.255.255.255  eth1
172.64.3.10      172.64.3.10     255.255.255.255  eth2
```

#### Environment Variables

The following environment variables can be set in `docker-compose.yml`:

- `PYTHONUNBUFFERED=1` - Ensures real-time Python output in logs

---

## Roadmap

- [x] **Core Router Functionality** - IP forwarding, ARP, ICMP implemented
- [x] **POX Controller Integration** - OpenFlow handlers connected
- [x] **Automated Test Suite** - 11 comprehensive test cases
- [x] **Dockerization** - One-command deployment
- [x] **Web-Based Terminal** - Real-time Mininet CLI via browser
- [ ] **Visual Topology Diagram** - SVG-based network visualization with live link status
- [ ] **Enhanced Web UI** - Pre-built command buttons for common operations
- [ ] **CI/CD Pipeline** - Automated testing on GitHub Actions
- [ ] **Performance Metrics** - Latency, throughput, packet loss tracking
- [ ] **Multi-Router Topology** - Expand to support routing between multiple routers
- [ ] **Unit Tests** - Isolated tests for individual router components

---

## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<!-- Note: No LICENSE file was detected. Consider adding one. -->

---

## Contact / Support

**Author:** Jason Tran

📧 **Email:** [tran219jn@gmail.com](mailto:tran219jn@gmail.com)

🌐 **Website:** [jasontran.pages.dev](https://jasontran.pages.dev/)

---

**Enjoying this project?** ⭐ Star this repository to show your support!

