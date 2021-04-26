#!/bin/bash
#SBATCH -N 8
#SBATCH -C knl
#SBATCH -q debug
#SBATCH -J seedot
#SBATCH -t 00:30:00

#OpenMP settings:
export OMP_NUM_THREADS=1
export OMP_PLACES=threads
export OMP_PROC_BIND=spread


#run the application:
module load python
srun -n 8 --cpu_bind=cores time python3 SeeDot-dev.py -a fastgrnn -e fixed -t x86 -m red_disagree -n 1 -d usps10

