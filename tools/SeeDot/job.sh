#!/bin/bash
#SBATCH -N 4
#SBATCH -C knl
#SBATCH -q debug
#SBATCH -J seedot
#SBATCH -t 00:30:00

#OpenMP settings:
export OMP_NUM_THREADS=2

#run the application:
module load python
rm -rf temp*
srun -n 4 -c 272 time python3 SeeDot-dev.py -a fastgrnn -e fixed -t x86 -m red_disagree -n 1 -d usps10

