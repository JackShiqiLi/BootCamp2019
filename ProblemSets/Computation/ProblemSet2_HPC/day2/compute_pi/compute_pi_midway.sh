#!/bin/bash
# a sample job submission script to submit an MPI job to the sandyb partition on Midway1

# set the job name to compute_pi
#SBATCH --job-name=compuite_pi

# send output to compute_pi.out
#SBATCH --output=compute_pi.out

#SBATCH --account=rccguest9465

# this job requests 1 core. Cores can be selected from various nodes.
#SBATCH --ntasks=1

# Run the process
./compute_pi.exec
