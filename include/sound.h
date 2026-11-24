/* The sound player/voice object (player slots and gStreamSoundPlayer): one
 * voice spread over up to 32 hardware channels, played in fixed segments. */
#ifndef SOUND_H
#define SOUND_H

#define SOUND_FLUSH_BLOCK           0x01 /* wait for space to submit the queued commands */

/* The pre-sleep and post-sleep list nodes begin at the stop and release
 * callbacks. Each node contains a callback, its argument and a next pointer. */
#define SOUND_PLAYER_PLAY_MODE      0x20 /* s32 hardware play mode (0 = normal, 1 = half size) */
#define SOUND_PLAYER_FLAGS          0x24 /* u32 bit 0: voice is playing, bit 1: its channels are set up */
#define SOUND_PLAYER_STOP_CB        0x08 /* void (*)(void *player): stops the voice's hardware channels */
#define SOUND_PLAYER_STOP_DATA      0x0C /* void *argument the stop callback is called with */
#define SOUND_PLAYER_RELEASE_CB     0x14 /* s32 (*)(void *player): ends its segments, then stops the channels */
#define SOUND_PLAYER_RELEASE_DATA   0x18 /* void *argument the release callback is called with */
#define SOUND_PLAYER_NOTE_BYTES     0x28 /* s32 sample bytes per note/channel */
#define SOUND_PLAYER_SEGMENTS       0x2C /* s32 segments the samples are split into */
#define SOUND_PLAYER_SEGMENT_CB     0x30 /* void (*)(s32 mode, s32 notes, s32 *offsets, s32 size, s32 arg, s32 arg2) */
#define SOUND_PLAYER_CB_ARG         0x34 /* s32 argument passed to the segment callback */
#define SOUND_PLAYER_CURRENT_SEGMENT 0x38 /* s32 segment being played */
#define SOUND_PLAYER_VOLUME         0x3C /* s32 player volume the channel volumes are based on */
#define SOUND_PLAYER_HW_CHANNEL     0x40 /* s32 allocated hardware channel index */
#define SOUND_PLAYER_CHANNEL_MASK   0x44 /* u32 mask of the hardware channels in use */
#define SOUND_PLAYER_NOTE_COUNT     0x48 /* s32 number of notes/channels */
#define SOUND_PLAYER_NOTES          0x4C /* u8[] note/channel id list */

#define SOUND_PLAYER_FLAG_PLAYING   0x0001 /* SOUND_PLAYER_FLAGS bit: voice is playing */
#define SOUND_PLAYER_FLAG_CHANNELS  0x0002 /* SOUND_PLAYER_FLAGS bit: the voice's hardware channels are allocated */
#define SOUND_PLAY_MODE_HALF        1      /* play mode that uses half the note bytes */

/* The ARM9-side per-channel timer callbacks (gSoundChannelCallbacks, 8 entries
 * indexed by hardware channel).  An entry is {callback, argument, generation};
 * Sound_StartChannelTimer stores them and sends the bumped generation to the
 * ARM7 with sound command 0x12, whose reply must echo it before the callback
 * runs (func_020097bc). */
#define SOUND_CHANNEL_CALLBACK_CALLBACK 0x00 /* void (*)(void *arg): the channel's timer callback */
#define SOUND_CHANNEL_CALLBACK_ARG      0x04 /* void * argument passed to the callback */
#define SOUND_CHANNEL_CALLBACK_GEN      0x08 /* u8 generation counter for the channel */
#define SOUND_CHANNEL_CALLBACK_SIZE     0x0C /* bytes per entry */
#define SOUND_CHANNEL_CALLBACK_COUNT    8    /* entries in the table */

/* The sound player handle: what Sound_StartPlayer (main_0202DBAC) fills in and
 * the segment callback (Sound_NextSegment) services.  One sound playing on a
 * set of hardware channels; separate from the voice object above. */
#define SOUND_HANDLE_TYPE          0xC0  /* u8 sound kind (0 = sample, 1/2 streamed) */
#define SOUND_HANDLE_CHANNELS      0xC2  /* u8 channels the sound asks for */
#define SOUND_HANDLE_RATE          0xC4  /* u16 sample rate */
#define SOUND_HANDLE_TIMER_PERIOD  0xC6  /* u16 hardware timer period */
#define SOUND_HANDLE_FLAGS         0x110 /* u32 player flag bits */
#define SOUND_HANDLE_REQUEST_COUNT 0x11C /* s32 segment requests queued for this player */
#define SOUND_HANDLE_CHANNEL_REFS  0x120 /* s32 voice-channel acquisitions the player holds */
#define SOUND_HANDLE_MAX_CHANNELS  0x124 /* u8 channel limit */
#define SOUND_HANDLE_SAMPLE_DATA   0x12C /* s32 sample data handle */
#define SOUND_HANDLE_CHANNEL_BYTES 0x130 /* s32 sample bytes per channel */
#define SOUND_HANDLE_LOOP_START    0x134 /* s32 loop start sample */
#define SOUND_HANDLE_LOOP_END      0x138 /* s32 loop end sample */
#define SOUND_HANDLE_SEGMENT_CB    0x13C /* s32 (*)(s32 mode, s32 *previous, s32 *next, s32 arg): fills the next streamed segment */
#define SOUND_HANDLE_SEGMENT_ARG   0x140 /* s32 argument to the segment callback */
#define SOUND_HANDLE_SOUND_ID      0x144 /* s32 id of the sound/sample being played */
#define SOUND_HANDLE_SLOT_INDEX    0x148 /* s32 the player slot's index, handed to a streamed sound's segment callback */
#define SOUND_HANDLE_VOLUME        0x158 /* s32 volume, 0..0x7F */
#define SOUND_HANDLE_SAMPLES_LEFT  0x160 /* s32 samples left in the current segment */
#define SOUND_HANDLE_START_CB      0x164 /* s32 (*)(void *player, s32 soundId): open the sound's data source */
#define SOUND_HANDLE_RELEASE_CB    0x168 /* void (*)(void *player): release the current data source */
#define SOUND_HANDLE_READ_CB       0x16C /* void (*)(void *player, void *dst, s32 bytes, s32 offset): read sample data */
#define SOUND_HANDLE_CLOSE_CB      0x170 /* void (*)(void *player): close the sound's data source */
#define SOUND_HANDLE_FILE_REQUEST  0x5C  /* the slot's file request, used to load its sample data */

#define SOUND_HANDLE_SOURCE_BASE   0xA4 /* sample file offset or memory base address */
#define SOUND_HANDLE_SOURCE_HEADER 0xA8 /* cached sample file header */
#define SOUND_SOURCE_HEADER_SIZE   0x40

/* The sound player slots (gSoundPlayerSlots), handed out by Sound_AcquirePlayer. */
#define SOUND_PLAYER_SLOTS  4    /* player slots in the pool */
#define SOUND_PLAYER_STRIDE 0x174 /* bytes per player slot */

/* Fields of a player slot that couple it to the handle variable that owns it. */
/* A player handle's fade envelope (SOUND_HANDLE_FADE): GetFadeValue ramps the
 * value from `start` to `target` over `length` ticks, AdvanceFade counting them. */
typedef struct FadeEnvelope {
    s32 start;    /* +0x00 value the fade starts from */
    s32 target;   /* +0x04 value it ramps to */
    s32 elapsed;  /* +0x08 ticks elapsed so far */
    s32 length;   /* +0x0C ticks the fade spans */
} FadeEnvelope;

#define SOUND_HANDLE_FADE      0xE8 /* FadeEnvelope the player's volume is faded through */

#define SOUND_HANDLE_OWNER    0x14C /* void ** the caller's handle variable, NULL when the slot is detached */
#define SOUND_HANDLE_PRIORITY 0x150 /* s32 priority of the sound in the slot: a new sound replaces it only with at least this priority */

/* Test one bit of a SOUND_HANDLE_FLAGS word the way the game reads it (a signed
 * shift pair); `bit` is the bit number, 0 being the lowest bit. */
#define SOUND_HANDLE_FLAG_IS_SET(flags, bit) ((s32) ((flags) << (31 - (bit))) >> 31)

/* Bits of SOUND_HANDLE_FLAGS. */
#define SOUND_HANDLE_BIT_ACTIVE   0 /* the slot holds a sound and its voice is allocated */
#define SOUND_HANDLE_BIT_PLAYING  1 /* the player is producing sound */
#define SOUND_HANDLE_BIT_PENDING  2 /* the voice is waiting for its first segment */
#define SOUND_HANDLE_BIT_STOPPING 3 /* a stop/fade-out is finishing */
#define SOUND_HANDLE_BIT_STREAMED 4 /* the sound is streamed (SOUND_HANDLE_TYPE 2) */
#define SOUND_HANDLE_BIT_ENDED    5 /* the sound reached its last segment */
#define SOUND_HANDLE_BIT_MONO     6 /* the sound plays mono (one channel) */

/* The streamed-sound state (gStreamSoundState); its streamed voice object
 * (gStreamVoice) starts at +0x48. */
#define STREAM_STATE_VOICE 0x48 /* s32 first word of the streamed voice: nonzero while open */

/* The sound driver's one-time init block (gSoundInitState): the done flag its
 * setup checks, and the handlers it installs to reset the driver. */
#define SOUND_INIT_DONE    0x0C /* s32 nonzero once the driver has been set up */
#define SOUND_INIT_STOP    0x10 /* void (*)(void) stops every channel and waits for the driver */
#define SOUND_INIT_SILENCE 0x1C /* void (*)(void) silences the streamed sound buffers */

/* Fields of the streamed sound voice (gStreamVoice). */
#define STREAM_VOICE_ACTIVE   0x00 /* s32 nonzero while a stream is open */
#define STREAM_VOICE_ENDED    0x04 /* s32 1 when the stream reached its end */
#define STREAM_VOICE_RESERVED 0x20 /* u32 channels reserved for the stream */
#define STREAM_VOICE_MASK_A   0x24 /* u32 first channel mask stopped with the stream */
#define STREAM_VOICE_MASK_B   0x28 /* u32 second channel mask stopped and cleared */
#define STREAM_VOICE_CHANNEL  0x2C /* s32 hardware channel index, -1 when none */
#define STREAM_VOICE_ENVELOPE 0x3C /* envelope state driven by the func_0202ef* helpers */
#define STREAM_VOICE_REFILL   0x4C /* s32 nonzero while a buffer is being refilled */
#define STREAM_VOICE_VOLUME   0x50 /* s32 last volume written to the hardware */

/* A loaded sound-archive file: the word at +0x18 of its header is the offset
 * from the file to the data block its entries live in. */
#define SOUND_ARCHIVE_DATA_OFFSET  0x18 /* s32 offset in the file of the archive's data block */
#define SOUND_ARCHIVE_DATA_BLOCK   0x8C /* void * the data block (from DATA_OFFSET) */
#define SOUND_ARCHIVE_TABLE_OFFSET 0x20 /* s32 offset in the file of the object table */
#define SOUND_ARCHIVE_TABLE        0x84 /* s32 * the object table (from TABLE_OFFSET) */
#define SOUND_ARCHIVE_FILE_OFFSET  0x10 /* s32 offset in the file of the object file */
#define SOUND_ARCHIVE_FILE         0x88 /* void * the object file (from FILE_OFFSET) */
#define SOUND_ARCHIVE_OPENED       0x30 /* s32 nonzero once the archive's file request is open */
#define SOUND_ARCHIVE_FILE_REQUEST 0x34 /* u8[0x48] the FSFileRequest the archive's file is read through */
#define SOUND_ARCHIVE_FILE_RANGE   0x7C /* the archive file's resolved byte range, reused to reopen it */
#define SOUND_ARCHIVE_ENTRY_COUNT  8    /* s32 objects in the table */
#define SOUND_ARCHIVE_ENTRIES      12   /* the objects: 16 bytes each */
#define SOUND_ARCHIVE_ENTRY_SIZE   16
#define SOUND_ARCHIVE_ENTRY_OFFSET 0    /* s32 offset in the file of the object's data */
#define SOUND_ARCHIVE_ENTRY_DATA   8    /* void * the object's data (from ENTRY_OFFSET) */

/* The resource tables inside the archive's loaded data block
 * (SOUND_ARCHIVE_DATA_BLOCK): each is a {u32 count; s32 offset[count];} section
 * whose offsets are relative to the block, and the GetSound*Record accessors
 * return the record at an index. */
#define SOUND_DATA_SEQUENCE         0x08 /* sequence table */
#define SOUND_DATA_SEQUENCE_ARCHIVE 0x0C /* sequence-archive table */
#define SOUND_DATA_BANK             0x10 /* sound-bank table */
#define SOUND_DATA_WAVE_ARCHIVE     0x14 /* wave-archive table */
#define SOUND_DATA_CHANNEL          0x18 /* channel table */
#define SOUND_DATA_GROUP            0x1C /* sound-group table */
#define SOUND_DATA_PLAYER_CHANNELS  0x20 /* per-player-slot channel assignment records: {u8 count; u8 channels[count]} */
#define SOUND_DATA_SOUND            0x24 /* sound table (GetSoundRecord) */

/* One file of a sound archive's file table (at SOUND_ARCHIVE_TABLE): where its
 * data sits in the archive file and, once loaded, the pointer to it. */
typedef struct SoundArchiveFileEntry {
    s32 offset;    /* +0x00 offset in the archive file of the file's data */
    u32 size;      /* +0x04 bytes of the file's data */
    void *data;    /* +0x08 the file's data, 0 while it is not loaded */
    s32 unknown0C; /* +0x0C */
} SoundArchiveFileEntry; /* 16 bytes */

/* The file table at SOUND_ARCHIVE_TABLE: the number of files at +8, then that
 * many 16-byte entries. */
typedef struct SoundArchiveFileTable {
    u8 pad00[8];
    u32 count;                      /* +0x08 number of files */
    SoundArchiveFileEntry files[1]; /* +0x0C */
} SoundArchiveFileTable;

/* One entry of a loaded sound archive (12 bytes): the sound it names, the bank
 * it is played with, its volume, pan, priority, and the player channel it is
 * played on. */
typedef struct SoundArchiveEntry {
    s32 soundId;  /* +0x00 sound id of the entry */
    u16 bankId;   /* +0x04 sound bank the entry is played with */
    u8  volume;   /* +0x06 volume */
    u8  pan;      /* +0x07 pan */
    u8  priority; /* +0x08 priority: a voice of higher priority replaces a lower one */
    u8  channel;  /* +0x09 player channel/slot the entry is played on */
} SoundArchiveEntry; /* 12 bytes */

/* One record of the sound archive's sequence table (GetSoundSequenceRecord):
 * the archive file holding the sequence and the bank it is played with. */
typedef struct SoundSequenceRecord {
    s32 fileId;   /* +0x00 file id of the sequence in the archive */
    u16 bankId;   /* +0x04 sound bank the sequence is played with */
    u8  volume;   /* +0x06 */
    u8  pan;      /* +0x07 */
    u8  priority; /* +0x08 priority of the playback */
    u8  channel;  /* +0x09 player channel the sequence is played on */
} SoundSequenceRecord;

/* One record of the sound archive's sequence-archive table
 * (GetSoundSequenceArchiveRecord): the archive file it names. */
typedef struct SoundSequenceArchiveRecord {
    s32 fileId;   /* +0x00 file id of the sequence archive in the archive */
} SoundSequenceArchiveRecord;

/* One record of the sound archive's sound table (SOUND_DATA_SOUND, GetSoundRecord):
 * the playback parameters of one sound, read when it is started on a player. */
#define SOUND_RECORD_SOUND_ID 0x00 /* s32 value handed to the player's start/segment callbacks */
#define SOUND_RECORD_PRIORITY 0x05 /* u8 priority of the sound in its player slot */
#define SOUND_RECORD_SLOT     0x06 /* u8 index of the player slot the sound plays on */

/* A sound group of the sound archive: a count and that many items, each saying
 * which kind of sound resource it names and the load flags its loader gets. */
typedef struct SoundGroupItem {
    u8  type;   /* +0x00 SOUND_GROUP_* */
    u8  flags;  /* +0x01 load flags handed to the item's loader */
    u8  pad02[2];
    s32 index;  /* +0x04 id in the table of that kind (sequence, bank, ...) */
} SoundGroupItem; /* 8 bytes */

typedef struct SoundGroup {
    u32 count;               /* +0x00 number of items */
    SoundGroupItem items[1]; /* +0x04 */
} SoundGroup;

/* SoundGroupItem::type */
enum {
    SOUND_GROUP_SEQUENCE         = 0,
    SOUND_GROUP_BANK             = 1,
    SOUND_GROUP_WAVE_ARCHIVE     = 2,
    SOUND_GROUP_SEQUENCE_ARCHIVE = 3
};

/* An id field of a sound-archive record meaning "no file/entry". */
#define SOUND_FILE_NONE 0xFFFF

/* `flags` bits of a SoundGroupItem (and of the loaders it selects): each resource
 * kind has its own bit, so a group can load only some of its items. */
#define SOUND_LOAD_SEQUENCE         0x01 /* load the sequence */
#define SOUND_LOAD_BANK             0x02 /* load the bank */
#define SOUND_LOAD_WAVE_ARCHIVE     0x04 /* load the wave archive */
#define SOUND_LOAD_SEQUENCE_ARCHIVE 0x08 /* load the sequence archive */

/* Flags byte of a packed wave-archive table record. */
#define SOUND_RECORD_WAVE_ENTRY_TABLE 0x01 /* the wave archive carries its own entry table */

/* A loaded wave archive file, as LoadWaveArchiveEntry and the packed-table
 * helpers read it: the entry count, then one data pointer per entry (a value
 * below 0x02000000 is an offset from the object itself), followed by one word
 * per entry giving where that entry's bytes start in the file (the next entry's
 * word, or the file size for the last entry, is where they end). */
#define WAVE_ARCHIVE_COUNT     0x38 /* s32 number of entries */
#define WAVE_ARCHIVE_ENTRIES   0x3C /* s32[count] per-entry data pointers (then the offsets) */
#define WAVE_ARCHIVE_FILE_SIZE 0x08 /* s32 total size of the archive file */

/* One record of the packed entry table a sound bank shares with the animation
 * system; the packed-table iterator reads it.  A type-1 record copies five u16
 * values at +0x02, of which the wave archive loader uses the first two: the
 * entry index in the archive and the archive slot it belongs to. */
typedef struct PackedBankEntry {
    u8  type;       /* +0x00 entry type: 1..5, 16 or 17 */
    u8  filler_01;
    u16 waveEntry;  /* +0x02 wave archive entry index */
    u16 waveSlot;   /* +0x04 wave archive slot (0..3) */
    u16 unk_06;
    u16 unk_08;
    u16 unk_0A;
} PackedBankEntry;

/* The sound driver's own voice pool and channel tables (separate from the
 * sound player object above).
 *
 * A linked list is a 12-byte header; every node carries a {prev, next} pair at
 * a fixed offset from the node's start (ListInit/ListAppend/ListRemove take
 * the header and compute the links from that offset). */
#define SOUND_LIST_COUNT       0x08 /* u16 nodes in the list */
#define SOUND_LIST_NODE_OFFSET 0x0A /* u16 offset of the links inside a node */

/* The sound heap header holds a frame heap handle followed by a section list.  A
 * section groups the data blocks allocated while it is the newest one; pushing a
 * section records the frame heap under the section's index so the section's
 * allocations can be rolled back. */
#define SOUND_HEAP_HEADER_SIZE 0x10
#define SOUND_HEAP_ALIGNMENT 4
#define SOUND_HEAP_FRAME         0x00 /* s32 the heap's frame-heap handle */
#define SOUND_HEAP_SECTIONS      0x04 /* the section list header (a 12-byte ListInit header) */
#define SOUND_HEAP_SECTION_COUNT 0x0C /* u16 sections currently on the heap (the section list's count word) */

/* One voice of gVoicePool (16 voices, 0x44 bytes each).  gActiveVoices and
 * gFreeVoices both link the voices at SOUND_VOICE_LINKS; a playing voice is
 * also linked into its channel's list at SOUND_CHANNEL_VOICE_LINKS. */
#define SOUND_VOICE_SIZE     0x44
#define SOUND_VOICE_PLAYER   0x00 /* void * player object that owns the voice (the player keeps the voice back at SOUND_PLAYER_VOICE) */
#define SOUND_VOICE_CHANNEL_BASE 0x04 /* void * the gSoundChannels entry whose voice list holds the voice */
#define SOUND_VOICE_HEAP     0x08 /* void * channel heap block the voice plays from (its SOUND_CHANNEL_HEAP_OWNER points back) */
#define SOUND_VOICE_LINKS    0x14 /* the {prev, next} pair of the voice lists */
#define SOUND_VOICE_ENVELOPE 0x1C /* 16-byte volume envelope state (Sound_ResetFade/eed8, AdvanceFade/GetFadeValue/IsFadeDone) */
#define SOUND_VOICE_STATE    0x2C /* u8 0 = free, 1 = keyed on, 2 = playing */
#define SOUND_VOICE_STARTED  0x2D /* u8 set once the voice's start command has been processed by the ARM7 */
#define SOUND_VOICE_STOP_PENDING 0x2F /* u8 set while the channel-stop command still has to be sent */
#define SOUND_VOICE_START_MARK   0x30 /* s32 ARM7 command counter the start command was queued at */
#define SOUND_VOICE_CHANNEL  0x3C /* u8 hardware channel the voice plays on */
#define SOUND_VOICE_PRIORITY 0x3D /* u8 priority: a request of lower priority cannot take this voice's place */
#define SOUND_VOICE_LAST_VOLUME  0x3E /* s16 hardware channel volume written last, so it is only resent when it changes */
#define SOUND_VOICE_VOLUME   0x40 /* u8 voice volume level, 0..127 */
#define SOUND_VOICE_EXPRESSION 0x41 /* u8 second volume level (expression), 0..127 */
/* SOUND_VOICE_STATE values. */
enum {
    SOUND_VOICE_FREE     = 0, /* the voice is on the free list */
    SOUND_VOICE_KEYED_ON = 1, /* its start command is queued, the ARM7 has not confirmed it yet */
    SOUND_VOICE_PLAYING  = 2  /* playing, released once its envelope has faded out */
};
#define SOUND_VOICE_COUNT    16
#define SOUND_PLAYER_VOICE   0x00 /* void * driver voice currently attached to a player, NULL when none */

/* A data block a Sound_AllocDataBlock call takes from a sound heap: a 0x20-byte
 * header (its +0/+4 links put it on the pool's block list) in front of the
 * payload.  When the block is freed its callback gets the payload, the payload
 * size and the two fields below. */
#define SOUND_BLOCK_SIZE      0x08 /* s32 payload bytes the block was allocated for */
#define SOUND_BLOCK_FREE      0x0C /* void (*)(void *payload, s32 size, s32 arg, s32 index) */
#define SOUND_BLOCK_FREE_ARG  0x10 /* s32 argument passed to the free callback (the block's owner) */
#define SOUND_BLOCK_INDEX     0x14 /* s32 index passed to the free callback */
#define SOUND_BLOCK_DATA      0x20 /* payload start, right after the header */

/* One channel of gSoundChannels (32 channels, 0x24 bytes each): the voices and
 * the sequences playing through it, its voice limit and its volume. */
#define SOUND_CHANNEL_SIZE        0x24
#define SOUND_CHANNEL_VOICE_LIST  0x00 /* list of voices, links at voice+0xC */
#define SOUND_CHANNEL_VOICE_LINKS 0x0C
#define SOUND_CHANNEL_SEQ_LIST    0x0C /* list of sequences, links at their +0 */
#define SOUND_CHANNEL_VOICE_LIMIT 0x18 /* u32 voices the channel accepts */
#define SOUND_CHANNEL_UNK_1C      0x1C /* u32 cleared at start-up */
#define SOUND_CHANNEL_VOLUME      0x20 /* u8 volume, 0..SOUND_VOLUME_MAX */
#define SOUND_CHANNEL_COUNT       32

/* A preallocated per-channel sequence-player heap: one of the sound data blocks
 * a channel keeps on its SOUND_CHANNEL_SEQ_LIST until a sequence player takes it
 * over.  The block's payload holds a heap (Sound_CreateHeap) the player then
 * allocates its sequences from; a data block's free callback destroys that heap
 * when the block is freed and detaches the node from the player that held it, or
 * from the channel's list when nobody did. */
#define SOUND_CHANNEL_HEAP_RESERVED 0x14 /* the node's fields, in front of its heap memory */
#define SOUND_CHANNEL_HEAP_HEAP     0x08 /* void * the heap created in the payload, NULL at first */
#define SOUND_CHANNEL_HEAP_OWNER    0x0C /* void * sequence player using the heap, NULL when free */
#define SOUND_CHANNEL_HEAP_CHANNEL  0x10 /* s32 channel whose list the node belongs to */

/* One of the 32 records of the loaded sound archive's channel table: how many
 * heaps are preallocated for a channel, the volume written to it and the size
 * of each of those heaps. */
typedef struct SoundChannelRecord {
    u8  count;    /* +0x00 heaps preallocated for the channel */
    u16 volume;   /* +0x02 channel volume */
    s32 heapSize; /* +0x04 bytes of each heap */
} SoundChannelRecord;

#define SOUND_VOLUME_MAX 0x7F /* full volume, in the 0..0x7F range */
#define SOUND_VOLUME_LEVELS 3  /* volume levels (master, user setting, fade) multiplied into a channel's effective volume */

/* Per-hardware-channel state (gSoundChannelSampleState), two s32 words per channel,
 * indexed by the note id the player lists at SOUND_PLAYER_NOTES: the sample
 * address the channel's current segment starts at and the timer period it is
 * played with.  The sound player fills it when a voice starts and reads it back
 * for every segment. */
#define SOUND_CHANNEL_STATE_STRIDE  8 /* bytes per channel: SOUND_CHANNEL_SAMPLE_ADDR + one word */
#define SOUND_CHANNEL_SAMPLE_ADDR   0 /* s32 address of the channel's current sample */
#define SOUND_CHANNEL_TIMER_PERIOD  4 /* s32 timer period the channel plays at */

/* The sound driver's hardware-channel masks (gSoundChannelMasks), one bit per
 * channel: which ones the voices/streamed players are running on, which ones
 * Sound_AllocChannel has handed out, and which ones Sound_ReserveChannels has
 * reserved from the sound library. */
#define SOUND_CHANNEL_MASK_VOICE    0x00 /* u32: channels the voices and streamed players use */
#define SOUND_CHANNEL_MASK_ALLOC    0x04 /* u32: channels Sound_AllocChannel handed out */
#define SOUND_CHANNEL_MASK_RESERVED 0x08 /* u32: channels reserved by Sound_ReserveChannels */

/* The game's sound wrapper state (gSoundState): the SDK sound player it keeps
 * running, the heap that player lives in, and the sound ids already started this
 * frame (a sound effect plays at most once per frame). */
#define SOUND_STATE_ENABLED      0x00 /* u8 nonzero once the sound system is up */
#define SOUND_HEAP_BYTES         0xD0000 /* bytes the driver takes from the game heap for its own sound heap */
#define SOUND_WORKER_PRIORITY    10  /* TaskCreate priority of the sound worker task */
#define SOUND_STATE_READY        0x04 /* u8 nonzero once the sound player can be addressed */
#define SOUND_STATE_PLAYER       0x10 /* void *SDK sound player */
#define SOUND_STATE_HEAP         0x14 /* s32 sound heap block */
#define SOUND_STATE_PLAYED_COUNT 0x18 /* s32 sound ids started this frame */
#define SOUND_STATE_FRAME        0x1C /* s32 gFrameCounter the count belongs to */
#define SOUND_STATE_SOUND_ACTIVE    0x08 /* s32 nonzero while the streamed sound player gMusicSoundPlayer is active */
#define SOUND_STATE_SEQUENCE_ACTIVE 0x0C /* s32 nonzero while the music sequence player gMusicSequencePlayer is active */
#define SOUND_PLAYED_MAX         8    /* sound ids remembered per frame (gSoundFrameIds) */
#define SOUND_SLOT_COUNT         4    /* sound effect slots (gSoundSlotHandles) */

/* A segment of a playing sound queued for the sound task (one request per
 * segment, eight request nodes in gSoundRequestPool, 0x30 bytes each; the list
 * links sit at +0 and +4 so a request is on one list at a time). */
#define SOUND_REQUEST_MAX_NOTES  6    /* note buffers one request can carry */
#define SOUND_REQUEST_PLAYER     0x08 /* void *player the segment plays on */
#define SOUND_REQUEST_MODE       0x0C /* s32 0 = first segment, 1 = continuation */
#define SOUND_REQUEST_NOTE_COUNT 0x10 /* s32 note buffers to fill */
#define SOUND_REQUEST_BUFFERS    0x14 /* u32 *[MAX_NOTES] the note buffers to fill */
#define SOUND_REQUEST_SIZE       0x2C /* s32 bytes to fill in each note buffer */
#define SOUND_REQUEST_STRIDE     0x30
#define SOUND_REQUEST_COUNT      8    /* request nodes in gSoundRequestPool */

/* The sound task (gSoundWorker): the worker's thread object with its stack
 * inside it, the wait queue the worker sleeps on and the queue of segment
 * requests.  The worker fills each request's note buffers, then frees it. */
#define SOUND_TASK_WAIT_QUEUE      0x4C0 /* OSThreadQueue the worker sleeps on: head at +0, tail at SOUND_TASK_WAIT_QUEUE_TAIL */
#define SOUND_TASK_WAIT_QUEUE_TAIL 0x4C4 /* tail of the worker's wait queue */
#define SOUND_TASK_LOCK            0x4C8 /* OSMutex guarding the request queue */
#define SOUND_TASK_REQUEST_QUEUE   0x4E0 /* list of pending segment requests, links at +0 */
#define SOUND_WORKER_STACK_SIZE    0x400 /* bytes of stack the worker thread is given inside gSoundWorker */

/* The sound task's global state (gSoundWorkerState): whether the task exists,
 * the task a sound's first segment is queued on (NULL = gSoundWorker) and the
 * ADPCM decode state streamed sounds are decoded into. */
#define SOUND_TASK_STATE_READY   0x00 /* s32 nonzero once the task is initialised */
#define SOUND_TASK_STATE_TASK    0x04 /* void *task first segments go on, or NULL */
#define SOUND_TASK_STATE_DECODER 0x08 /* u8 *streamed-sound ADPCM decode state */

/* Menu sounds handed to PlaySoundEffect. */
#define SOUND_MENU_MOVE    0x10010 /* the cursor moved to the other option */
#define SOUND_MENU_CONFIRM 0x1000D /* the highlighted option was accepted */
#define SOUND_MENU_CANCEL  0x1000F /* the choice was cancelled */
#define SOUND_MENU_SELECT  0x10019 /* the highlighted list entry changed or was chosen */
#define SOUND_MENU_TAB     0x10020 /* the active tab changed */
#define SOUND_MENU_CLOSE   0x10022 /* the screen's close/back action was taken */

/* The text window's sounds: the open one plays from NotifyWindowOpened, the
 * close one from func_0208a714; a window opened during a link session plays
 * SOUND_WINDOW_LINK on sound slot 0 instead of the open sound. */
#define SOUND_WINDOW_OPEN  0x125
#define SOUND_WINDOW_CLOSE 0x124
#define SOUND_WINDOW_LINK  0x10013

/* Sounds played while a weather change is applied, one per new weather: clear,
 * rain, snow, sandstorm. */
#define SOUND_WEATHER_CLEAR     0xd4
#define SOUND_WEATHER_RAIN      0xd6
#define SOUND_WEATHER_SNOW      0xd5
#define SOUND_WEATHER_SANDSTORM 0xd7

/* Battle music tracks: the CO-power theme that replaces the map's music while a
 * player's CO power is active (GetCoPowerMusicTrack).  Armies 1..7 use the first,
 * every other army the second. */
#define SOUND_CO_POWER_THEME_1 0x10002
#define SOUND_CO_POWER_THEME_2 0x10003

/* The delayed one-shot sound-effect sprite (class gDelayedSoundEffectClass,
 * spawned by SpawnSoundEffectAtTile / func_0208f998 and updated by
 * UpdateDelayedSoundEffect): it waits SOUND_EFFECT_DELAY frames, plays
 * SOUND_EFFECT_ID at SOUND_EFFECT_VOLUME with SOUND_EFFECT_PAN, then deletes
 * itself. */
#define SOUND_EFFECT_DELAY   0x52 /* s16 frames to wait before playing */
#define SOUND_EFFECT_ELAPSED 0x54 /* s16 frames elapsed so far */
#define SOUND_EFFECT_ID      0x5C /* s32 sound effect to play */
#define SOUND_EFFECT_VOLUME  0x60 /* s32 volume it is played at */
#define SOUND_EFFECT_PAN     0x64 /* s32 stereo pan */

/* The running music track (gCurrentMusicTrack) and the object that fades it out
 * (class gMusicFadeOutClass, spawned by FadeOutMusicOverFrames). */
#define MUSIC_NONE        0xFFFF /* gCurrentMusicTrack value when no track plays */
#define MUSIC_FADE_FRAMES 0x6C   /* s16 frames left before the fade-out object stops the track */

#endif
