#!/bin/bash -l

#SBATCH --ntasks=1
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=20

#SBATCH --time=00:01:00


#SBATCH --job-name=dot_prod
#SBATCH --output=dot_prod10000.out

export OMP_NUM_THREADS=20


### openmp executable
./dot_prod.exec
