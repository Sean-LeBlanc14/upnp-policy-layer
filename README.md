# CSC3201 Computer Security Project

## Hardware and Dependencies

### Hardware

| Device |
| --- |
| Raspberry Pi 4 8GB |
| ESP32 S3 |

### Dependencies

| Component | Version |
| --- | --- |
| OpenWRT | 25.12.5 (Factory SQUASHFS) |
| miniupnpd-nftables | 2.3.9 |
| EasyDDNS | 1.8.0 |
| TinyUPnP | 3.2.0 |

## Reproduction

**Configuring miniupnpd on Raspberry Pi:**

```bash
uci set upnpd.config.external_iface='wan'
uci set upnpd.config.internal_iface='lan'
uci set upnpd.config.enabled='1'
uci set upnpd.config.secure_mode='1'
uci set upnpd.config.log_output='1'
uci commit upnpd
```
