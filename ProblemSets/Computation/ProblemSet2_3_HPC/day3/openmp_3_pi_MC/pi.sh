#!/bin/bash -l

#SBATCH --ntasks=1
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=1

#SBATCH --time=00:01:00


#SBATCH --job-name=pi
#SBATCH --output=pi.out

export OMP_NUM_THREADS=1


### openmp executable
./pi_MC_omp.exec
