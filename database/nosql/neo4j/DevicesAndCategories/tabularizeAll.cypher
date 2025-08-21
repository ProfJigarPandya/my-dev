WITH *
MATCH (device:Device)
ORDER BY device.type
RETURN device.name AS DeviceName, device.type AS DeviceType