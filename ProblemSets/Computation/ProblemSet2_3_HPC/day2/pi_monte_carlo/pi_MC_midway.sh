#!/bin/bash
# a sample job submission script to submit an MPI job to the sandyb partition on Midway1

# set the job name to compute_pi
#SBATCH --job-name=pi_MC

# send output to pi_MC.out
#SBATCH --output=pi_MC.out

#SBATCH --account=oselab

# this job requests 1 core. Cores can be selected from various nodes.
#SBATCH --ntasks=1

# Run the process
./pi_MC.exec
1000000
