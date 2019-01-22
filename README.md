# Chalmers Signal
The Chalmers Signal is an internet enabled dial designed for reporting shelter occupancy.
![photo of latest prototype]()

Shelter referrals can be a cumbersome process. Shelter staff often wait on hold for Toronto's referral line, or call other shelter staff directely, in order to make a referral. Shelter occupancy reporting is done manually over the phone, or through custom software built by city staff called SMIS, which requires training.

The Chalmers Signal aims to make shelter occupancy reporting as easy as turning a dial.

In our user research we conducted as **[Project Basecount](https://basecount.netlify.com)**, shelter staff told us that being able to see the shelter occupancy of other shelters at a glance would be *invaluable*.

---
The Chalmers Signal started with an experiment we ran at the [St. Felix Respite site](https://stfelixcentre.ca/).

![](https://media.giphy.com/media/7zDZJI1XRbogHWWfC7/giphy.gif)

The internet button at St. Felix sends an email to us when they run out of [chalmers cards](chalmerscards.com). It works well too! The shelter staff tell me they get a kick out of pressing a button to have one of us show up a few hours later.

---

![St. Felix Button](https://i.imgur.com/IOCCQx2.jpg)

## Here's a rendering of our latest prototype

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
