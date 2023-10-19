# ssh tunnel with built in ssh server as snap

This repository contains ssh tunnel with optional built in ssh server.

## ssh tunnel

ssh tunnel with built in ssh server. It can be run stand alone as ssh-tunnel and bind on local ssh server. Or it can be used as boilerplate to be added into own snap to enable remote application debugging without reliance on system ssh server. At which point ssh session runs confined in host snap context.

At install ssh key is generated and stored to configurations:
`$ snap get ondra-snap-ssh-debug ssh-tunnel.local.ssh-pub-key`
add this to your remove server to allow auto connection.

By default ssh tunnel and ssh server are disabled:
To configure ssh tunnel, use following configuration (with own values):
```
$ snap set ondra-snap-ssh-debug \
   ssh-tunnel='{ "remote": {"target": "162.162.11.1", "forwarding-port": "2020", "remote.ssh-port": "22", "user": "ubuntu" }, "local": { "address": "localhost"}}'
```

## Built in ssh server
To use built in ssh server, use following example:
```
$ snap set ondra-snap-ssh-debug ssh-tunnel.local.port=2040
$ snap set ondra-snap-ssh-debug ssh-server='{ "enabled": "true", "authorized-keys" : "ssh-rsa AAAA&lt;MY SSH public key&gt;== ondrej.kubik"}'
```

Default user for built in ssh server is 'root', use like:
```
$ ssh -p 2040 root@<ip address>
$ scp -P <local file> 2040 root@<ip address>:
```
