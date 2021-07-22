devices="stm32l476rg lm3s811 MK64F12 TM4C123GH6PM"
algos="round-robin weighted-round-robin"

echo "#WeeOs Configuration File" > config.mk
echo "#Please edit this file to configure WeeOs" >> config.mk
echo "" >> config.mk

echo "#Name of the generated elf file" >> config.mk
echo "PROJECT := main" >> config.mk
echo "" >> config.mk

echo "#Device for which the project has to be made" >> config.mk
echo "#Available Devices: $devices" >> config.mk
echo "DEVICE := stm32l476rg" >> config.mk
echo "" >> config.mk

echo "#Scheduling Algorithm used in the App" >> config.mk
echo "#Available scheduling algorithms: $algos" >> config.mk
echo "SCHD_ALG := round_robin" >> config.mk

echo "configuration file config.mk generated"
echo "please edit config.mk before running make"
