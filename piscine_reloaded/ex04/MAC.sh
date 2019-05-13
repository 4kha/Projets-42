ifconfig | grep ether | sed 's/ether //g' | sed 's/ //g' | cut -c 2-
