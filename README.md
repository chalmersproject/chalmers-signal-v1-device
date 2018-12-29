# Chalmers Signal

I've been working on a way to provide live shelter capactity data!

![](https://media.giphy.com/media/7zDZJI1XRbogHWWfC7/giphy.gif)

I've been experimenting with internet buttons. Here is an image of the internet button at St. Felix that sends me an email when they run out of [chalmers cards](chalmerscards.com). It works well too! The shelter staff tell me they get a kick out of pressing a button to have me show up a few hours later.

![St. Felix Button](https://i.imgur.com/IOCCQx2.jpg)

## Here's a rendering of what a button responsible for reporting shelter capacity might look like:

![Chalmers Signal Rendering](https://i.imgur.com/DVjn7F7.png)

The button is a rotating switch. The green light means space available, the yellow means nearly full, and red means full. An LED lights up when the switch's selector aligns with it. 

The switch could live behind a reception desk of a main office, like the one pictured below (modeled after the desk at St. Felix):

![Chalmers Signal At Reception](https://i.imgur.com/xa07p7p.png)

The rotating selector switch rests on a desk, connected to power. A more visible signal-light is hung from the wall. The wall mounted light is so that everyone in the office has line of sight to whatever status they're broadcasting.

Finally, the switch would push it's status to a database and website frontend based on Filip Stepien's open source [Shelter Watch](https://shelter.filipstepien.com/). Parts of the frontend might also be borrowed from Civic Tech Toronto's [BaseCount](basecount.netlify.com). 

## Cost
The switch's design is intended to be inexpensive and to be assembled in a makerspace with a lasercutter and an electronics bench (e.g. [HackLab.TO](Hacklab.to) -- I am a member). I expect the material cost of each switch to be ~$20:
+ NodeMCU: $12, 
+ Wood: $1, 
+ Acrylic $2, 
+ 3 position rotary switch: $3, 
+ power cable: $2
+ maybe a battery??: $2
 
These prices are based off of Amazon, Creatron, and Plastic World prices. So the material cost of each switch can be lowered by buying from suppliers with longer shipping times.

## Time
A rough estimate of how long building these switches will take:
| Task      | Time (hrs) | 
|:---       |:---- |
| Design a first prototype of the 3 phase switch    |  7  |
| Laser cut and assemble prototype with case (rendered above) | 10 |
| Laser cut and assemble wall mounted light | 5 |
| Deploy website frontend and database | 10 |
| Make switches and lights for each OOTC location | 14 |
|-------------------------------------------------------------------|-------------------|
| Total | 46 |

> I understand that contracting with city departments can be complicated and slow. In the interest of avoiding delays, I am willing to volunteer my time to prepare these switches. I plan to apply for a community & events grant to cover material costs.