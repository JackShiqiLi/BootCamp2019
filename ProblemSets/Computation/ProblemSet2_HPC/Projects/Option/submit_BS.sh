#!/bin/bash
# a sample job submission script to submit an MPI job to the sandyb partition on Midway1

# set the job name to BS
#SBATCH --job-name=BS

# send output to BS.out
#SBATCH --output=BS.out


# this job requests 1 core. Cores can be selected from various nodes.
#SBATCH --ntasks=1

# Run the process
./BS.exec
