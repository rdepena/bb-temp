#! /bin/sh

#Script that will install bb-temp as a linux service
#similar to http://rdepena.com/configuring-a-node-js-service-in-linux/

echo "ensuring file is executable"
chmod +x tempservice

echo "moving the tempservice script to /etc/init.d/tempservice"
cp tempservice /etc/init.d/tempservice

echo "update rc.d"
update-rc.d tempservice defaults
