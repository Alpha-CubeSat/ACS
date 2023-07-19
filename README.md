# ACS
## Attitude Control System of Alpha CubeSat

### Branchs
`main` has the most updated version of the raw ACS dev files

`with-ekf` is a feature branch with Sam developed Extended Kalman Filter for IMU noises

### File Structure

The `LEGACY` folder contains all the previous MATLAB/SIMULINK files for storage purposes
And the production/development files are in the root dir of this repo

### Blocks
Davide's original code does not separate the **plant** and the **starshot controller**. 
In order to adapt the code to our microcontroller application. We separated his code to the previously mentioned two blocks.


**Plants**
Plantv5: a modified version of the original version, with different math blocks. (less power consumption?)
Plant_OG: a direct migration of Davide's code.


### NOTES 

`starshot_sim.slx` is Davide's original version. Which uses the cont. time derivative in starshot

In order to use discrete-time derivatives, we shall use a fix-step setting instead of a variable-step.

Some, if not all, the `StarshotACS` blocks seem to scale Kd in with `Izp`, making the input Kd ~500 times smaller.

