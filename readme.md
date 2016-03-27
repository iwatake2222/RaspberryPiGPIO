# GPIO on Raspberry Pi
* You will be able to:
	* Control GPIO by shell on Raspberry Pi
	* Control GPIO by the program you created on Raspberry Pi
	* Control GPIO by the program you created on Host PC (Cross Compile)
	* Understand how to user external library when cross compile
* Library in use
	* WiringPi <http://wiringpi.com/>
* I assume directory structure as:
	* raspberry/
		* mySrc/		# for basic compile
		* workspace/		# for eclipse
		* tools/
		* libraries/
			* wiringPi


## Install basic tools
```
pi$> sudo apt-get update
pi$> sudo apt-get upgrade
pi$> sudo apt-get install git git-core
```

## Install WiringPi
```
pi$> mkdir libraries
pi$> cd libraries
pi$> git clone git://git.drogon.net/wiringPi
pi$> cd wiringPi
pi$> ./build
pi$> cd ../
```

## Use WiringPi on shell
```
pi$> gpio -v
pi$> gpio readall
pi$> gpio -g mode 17 out
pi$> gpio -g write 17 1
pi$> gpio -g read 17
```

## Compile on Raspberry Pi
```
pi$> nano led.cpp
pi$> gcc led.cpp -lwiringPi
pi$> sudo ./a.out
```
[led.cpp is here](led.cpp)

## Compile on Host PC (Cross Compile)
* Refer to <https://github.com/take-iwiw/RaspberryPiCrossCompileSetup>

Do not "build". All you need is "make" and create .so
```
Host$> mkdir libraries
Host$> cd libraries
Host$> git clone git://git.drogon.net/wiringPi
Host$> cd wiringPi/wiringPi
Host$> make ARCH=arm CC=../../../tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin/arm-linux-gnueabihf-gcc
Host$> ln -s libwiringPi.so.2.32 libwiringPi.so
Host$> cd ../../../mySrc/
Host$> vi led.cpp
Host$> ARCH=arm ../tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin/arm-linux-gnueabihf-g++ led.cpp -I../libraries/wiringPi/wiringPi -L../libraries/wiringPi/wiringPi -lwiringPi
Host$> scp ./a.out pi@192.168.0.144:~/
```
[led.cpp is here](led.cpp)

```
pi$> sudo ./a.out
```

## Compile on Host PC with Eclipse (Remote Debug)
* Right click on the project in ProjectExplorer -> Properties
* C/C++ General -> Paths and Symbols
	* Includes tab
		* Languages: GNU C++
		* ADD : /home/myname/dev/raspberry/libraries/wiringPi/wiringPi
	* Library Paths tab
		* ADD : /home/myname/dev/raspberry/libraries/wiringPi/wiringPi
	* Library tab
		* ADD : wiringPi
