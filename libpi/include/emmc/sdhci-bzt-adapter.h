/**
 * An adapter for the emmc driver to be compatible to the bzt-sd library interface, DMA now working!!! 
 */
#ifndef SDHCI_H 
#define SDHCI_H 
#include "emmc/emmc.h"
#ifdef SDHOST_SD_H
#error "SDHOST adapter is included, , SDHCI adapter conflicts with the SDHOST adapter!"
#endif 
#define SDHCI_USE_DMA  1 
#define SD_OK                0
#define SD_TIMEOUT          -1
#define SD_ERROR            -2

#define SD_SET_SDCARD_GPIO   1 

int sdhci_sd_init(); 
void sdhci_sd_set_sdcard_gpio(); 
int sdhci_sd_readblock(unsigned int lba, unsigned char *buffer, unsigned int num);
int sdhci_sd_writeblock(unsigned char *buffer, unsigned int lba, unsigned int num);

#endif // ! SDHCI_H 

