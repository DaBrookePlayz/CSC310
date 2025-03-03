# How does this implementation differ from the traditional DSW approach.

## What is the impact of phase 1

There doesn't need to be as many rotations going on due to some nodes not being in the 'vine' shape (but are in the correct order) and thus it is more effecient

## What is the impact of phase 2

- we counted the number of various rotations
- used less-strict high balancing so less processing power is needed

## What tradeoff did you observe

- the vine is no longer vine-shaped
- searching may take a very slightly longer amount of time

## Can you think of other variations?

- Don't do the whole "vine" thing at all
- Not doing the reconstruction part and just enjoy the linked list