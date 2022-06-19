# NEWER Super Mario Bros. U
## Source Code

### Preamble

Well, here it is, the thing you've been awaiting for... years. Yep.

Yeah, so this is Newer U's code. This has been dumped pretty hastily on here with no testing or polishing of any kind, more or less completely in the same state as it was when the mod was cancelled.

Unfortunately, it's not actually very useful. It requires the compiler Nintendo licenses to Wii U developers, and making it work with another one is simply beyond our resources. And, of course, it was never finished, so a lot of this code was never meant to be used in its current state in the first place. So this is here more as a museum artifact rather than for serious usage. That being said, if you have any use for any of this, go for it ;)

### Licensing

The Newer SMBU source code and tools are released under the MIT license.
See the `LICENSE` file in this repository for full details.

Copyright (c) 2021 Newer Team

### Requirements*
#### *(as far as I can tell)

- Green Hill Software MULTI 5.3.27
- devkitPPC
- Python 3.x
- Python libraries: PyYAML, pyelftools

### What's Here

For one, the NewerU code hacks are all in the `files` folder. This uses a very NewerSMBW-like patching system, with the accursed yamls and all.

Naturally, there are symbol maps and headers used by NewerU's code. These could be helpful to others who would like to mod the game! It is recommended to use headers from [this repository](https://github.com/shibbo/NSMBU-Headers/) instead, though, as they are being maintained and updated past what was done for Newer U.

The source code itself includes many features, some of which ported from Newer Wii (ex. random Yoshi colours, magic platforms); and many things new to Newer U, like water waves, triple ? blocks, a "only show tiles when you get close" feature, and even a couple custom enemies.

There's also a little algorithm included in `Tech Demos` that was meant to be implemented for NewerU's space world (gravity for planets you could walk all the way around, like in Super Mario Galaxy).

Lastly, there's a lot of setup stuff in here, but it hasn't been used for years and may not work as-is.

### Credits
- Kinnay -- Coding, REing
- Grop -- Coding
- Shibboleet (MrRean) -- REing
- RoadrunnerWMC -- Tools, Tech Demo

### Questions?

If you have any inquiries, you can shoot us an email at <neweru@newerteam.com>. We'll do our best to respond, but please keep in mind that support for this is not our top priority, so we may not get to you/have an adequate answer. Feel free to poke at us anyway, though!

