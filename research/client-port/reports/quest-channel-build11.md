# Quest lists, command channels and catalogue completeness

The candidate adds QuestList 80 and command-channel FE30 conversion. It does not claim complete protocol or asset compatibility.

## Native evidence

- C4 QuestList handler 104020a0 parses quest IDs/states and a separate item list. GameEngine::AddQuestItem 1046e470 forwards to console slot 2b8. The pinned C4 NWindow constructor at 100825e6 installs vtable 101b3488; slot 2b8 points to 100023f0 (`ret 4`). Executing this complete forwarder and UI callback confirms that item records are ignored by this source UI. Conversion preserves quest IDs/states and supplies the 128-byte empty completion bitmap required by Interlude. Existing Interlude bitmaps remain unchanged. This does not invent completed quest history.
- FE30 preserves channel leader, member counts and party leader names. Interlude-only loot mode and unavailable leader object IDs default to zero. Both original invite/kick emitters serialize leader names, and differential native tests confirm identical requests. New party-member-details D0:26 remains blocked because C4 does not supply the required ID.
- Structural tests include full consumption, bounds, truncated rows and modern passthrough. Receive-hook tests exercise conversion and malformed rejection between a single decryption and the original queue; cipher state remains enabled for the next packet.
- Nine movement/item-drop methods produced matching bytes on 45 native vector pairs. CanNotMoveAnymore only covers its non-vehicle branch. See native-movement-requests.json; finite vectors do not prove all UI branches.

## Catalogue repair

Names are no longer used to exclude registered handlers. The Interlude catalogue now includes seven missing Pledge/PC-cafe registrations, including FE3C PledgeReceivePowerInfo. There are 304 C4 and 348 Interlude registered slots. An independent test enumerates handler assignments and static slot-zero initializers and checks the entire inventory. This establishes slot coverage, not full semantic compatibility.

## Clan permission findings and remaining work

C4 edits individual online members; Interlude C0 edits ranks. The C4 UI query actions are 1 (view), 2 (edit), and 3 (save 32-byte bitset), confirmed at NWindow callsites 1004e866, 1004e97a and 10087183. Its eleven checkboxes use bits 0..10, including title, crest, war, and broad clan-hall/castle rights. A rank ID cannot be substituted for a member object ID. A complete bridge needs member context and an interface preserving these C4 rights; no guessed privilege rewrite is enabled.

CharacterSelected 15 remains quarantined after the previous live regression. Missing/protected source assets and other unverified contracts remain open. Automated passing tests must not be described as complete gameplay validation.

## Exact legacy permission labels

The C4 permission window copies the 32-byte response at NWindow 10088250 and renders its checkboxes at 10086ee0. Widget creation and the original C4 sysstring-e.dat establish:

| C4 bit | Original label | Scope |
|---|---|---|
| 0 | Join a Clan | Clan |
| 1 | Give a Title | Clan |
| 2 | Viewing the Contents of a Warehouse | Clan |
| 3 | Clan Crest Management | Clan |
| 10 | Clan War | Clan |
| 4 | Entrance Authority | Clan hall |
| 5 | Other Rights | Clan hall |
| 6 | Dismiss | Clan hall |
| 7 | Opening a Door | Castle |
| 8 | Other Rights | Castle |
| 9 | Dismiss | Castle |

The four existing UserInfo indicator mappings (0→1, 1→2, 3→7, 10→5) are independently validated in native SetPledgePower tests. They are not a complete replacement for this editor or all its rights. In particular, broad legacy rights cannot be silently expanded into guessed Interlude granular privileges.

PetInventoryUpdate B3 was another extractor false difference: C4 pushes `hh`, initializes locals, then calls its decoder beyond the previous eleven-instruction scan window. Both handlers consume `h + count*(hh + dddhhhdhh)`, and differential native tests check every field for 0/1/3/64 rows. No packet rewrite is added.
