# ClickSpawn
Spawning actors at the location where user’s mouse clicked in 3D space. At the same time of actor spawned, it automatically trigger a squeeze animation.

To make it works, you have to do followings :
- Set up “TraceDistance" is details panel as it controls the farthest distance our mouse can reach
- Add an actor to the “ActorToSpawn” slot in details panel. This will be the actor we are going to spawn in the scene
- Add a curve float to “TimeCurve” slot. The squeezing animation will use the value stored inside the curve float as it’s movement
- Set up “SqueezeValue” in details panel. It decides the Squeeze value of the squeezing animation
- Ready to go


![ClickSpawn](https://github.com/TimChen1383/ClickSpawn_UE/assets/37008451/17b7d04c-78ba-482d-bb50-177a8c52497f)


