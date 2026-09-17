# GM character information and mounts — build 10

Candidate adds two C4→Interlude conversions. It does not complete the port.

## GMViewCharacterInfo 0x8F

Pinned C4 handler 10415800 reads 99 fields (format 107c5998); pinned Interlude handler 10426930 reads 143 (format 10889278). Conversion widens unsigned experience to Q, extends both equipment arrays, adds 34 augmentation halfwords, inserts effect after class ID and before max/current CP, and adds the Interlude tail. Missing feature flags/rank default to zero and colors to white. These are defaults, not equivalent C4 features. Output grows by 100 bytes.

`test_native_gm_info.py` executes both original decoders on synthetic records and compares every decoded field and final cursor. `test_structured_codec.py` checks exact output, truncations, capacity, modern passthrough and unknown variants. Unknown GM variants remain untouched. Live GM UI behavior is not yet verified.

## Ride 0x86

C4 handler 104145f0 reads four dwords; Interlude 10425930 reads seven. Append zero x/y/z to the 17-byte C4 packet; preserve complete 29-byte Interlude packets. The zero vector is a native sentinel, not a teleport destination:

- RiderEnter 106290e0 calls Core FVector equality at 10629128; equal-to-zero path copies pawn Location (+1bc/+1c0/+1c4) to arguments before 1062914d.
- RiderEnd 1061c960 does the same at 1061c9c4, before 1061c9e9.

`test_native_ride.py` executes these prefixes and the real Core equality function, verified by the pinned dependency hash. Both mount and dismount preserve fractional current coordinates for zero input and keep explicit nonzero coordinates unchanged. It stops before world mutation and does not claim to emulate the full game. Structural tests and native receive-hook tests cover the wire conversion and single decrypt sequence.

## Remaining scope

C0/30 clan privilege actions, QuestList 80 semantics, command channel FE30, CharacterSelected 15 live variants, unresolved catalogue contracts and asset references remain open. CharacterSelected stays quarantined. Native matches already demonstrated for warehouse/list requests remain unchanged.
