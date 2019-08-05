#!/bin/bash
# `a sample job submission script to submit a hybrid MPI/OpenMP job to the broadwl
# partition on Midway please change the --partition option if you want to use 
# another partition on Midway

# set the job name to BS
#SBATCH --job-name=BS_hybrid

# send output to BS-hybrid.out
#SBATCH --output=BS-hybrid.out

# this job requests 8 MPI processes
#SBATCH --ntasks=8


# and request 20 cpus per task for OpenMP threads
#SBATCH --cpus-per-task=20

# this job will run in the broadwl partition on Midway
#SBATCH --partition=broadwl

# load the openmpi default module
module load openmpi

# set OMP_NUM_THREADS to the number of --cpus-per-task we asked for
export OMP_NUM_THREADS=$SLURM_CPUS_PER_TASK

# Run the process with mpirun. Notice -n is not required. mpirun will
# automatically figure out how many processes to run from the slurm options
mpirun ./BS_hybrid.exec
