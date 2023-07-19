# ACS
Attitude Control System of Alpha CubeSat


### File Structure

The `LEGACY` folder contains all the previous MATLAB/SIMULINK files for storage purposes
And the production/development files are in the root dir of this repo


### NOTES 

`starshot_sim.slx` is Davide's original version. Which uses the cont. time derivative in starshot

In order to use discrete-time derivatives, we shall use a fix-step setting instead of a variable-step.

Some, if not all the `starshotsimv5.slx` seem to scale Kd in with `Izp` which makes the input Kd ~500 times smaller

