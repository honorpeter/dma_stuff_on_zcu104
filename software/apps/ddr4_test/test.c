#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>

#include "mem-io.h"
#include "utils.h"
#include "proto2_hw.h"


int main(int argc,char** argv)
{
    void* pcie_addr;

    off_t pcie_bar0_addr=BASE_ADDRESS;
    size_t pcie_bar0_size=PROTO_SIZE;

    pcie_addr=phy_addr_2_vir_addr(pcie_bar0_addr,pcie_bar0_size);
    if(pcie_addr==NULL) {
       fprintf(stderr,"can't mmap phy_addr %p with size %p to viraddr. you must be in root.\n",(void *)pcie_bar0_addr,(void *)pcie_bar0_size);
       exit(-1);
    }
    fprintf(stdout,"phy_addr %p with size %p to viraddr %p.\n",(void *)pcie_bar0_addr,(void *)pcie_bar0_size, pcie_addr);

    //fprintf(stdout,"FPGA ID: 0x%08X\n",read_reg(pcie_addr,FPGA_ID));
    //fprintf(stdout,"VERSION: 0x%08X\n",read_reg(pcie_addr,FPGA_VERSION));

    //write_reg(pcie_addr, LED_CONTROL, 0x02);

    const int Nram = (DDR4_SIZE/4)/64;
    uint32_t* write_data = (uint32_t*)malloc(Nram*sizeof(uint32_t));
    uint32_t* read_data  = (uint32_t*)malloc(Nram*sizeof(uint32_t));
    //uint32_t write_data[Nram];
    //uint32_t read_data[Nram];

    uint32_t* ddr4 = pcie_addr + DDR4_OFFSET;

    // Let's test the DDR4
    int errors;
    errors = 0;
    const int Ntest = 1;
    for (int j=0;j<Ntest;j++){

	// compute test data
    	for (int i=0; i<Nram; i++){
        	write_data[i] = rand();
    	}
	
	// copy to ddr4
	memcpy( ddr4, write_data, sizeof(write_data) );
	
	// read and check ddr4 data
	memcpy( read_data, ddr4, sizeof(write_data) );
    	for (int i=0; i<Nram; i++) if (read_data[i] != write_data[i]) errors++;

    }
    fprintf(stdout, "Ntest = %d, errors = %d\n", Ntest, errors);

    free(read_data);
    free(write_data);
    munmap(pcie_addr,pcie_bar0_size);

    return 0;
}

