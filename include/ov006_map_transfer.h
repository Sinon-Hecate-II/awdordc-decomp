/* The ov006 map-transfer screen: the object that exchanges campaign map records
 * between linked players, and the downloaded-map panel sprite it creates. */
#ifndef OV006_MAP_TRANSFER_H
#define OV006_MAP_TRANSFER_H

/* The ov006 map-transfer object: the campaign map id it exchanges, its transfer
 * mode, and the buffers it receives player entries (0x310 bytes each) and
 * expanded map records (0x6F8 bytes each) into. */
#define MAP_TRANSFER_MAP_ID      0x34 /* s32 campaign map id whose record is transferred */
#define MAP_TRANSFER_MODE        0x38 /* s32 transfer mode selecting the operation */
#define MAP_TRANSFER_MODE_UP_TO_LIMIT 0 /* collect up to 100 online players */
#define MAP_TRANSFER_MODE_NO_LIMIT    1 /* collect every online player */
#define MAP_TRANSFER_MODE_IDS         2 /* collect only the ids in MAP_TRANSFER_SOURCE */
#define MAP_TRANSFER_COUNT       0x3C /* s32 number of player entries collected */
#define MAP_TRANSFER_TARGET_ID   0x40 /* s64 online player id the transfer targets, entered by the number display */
#define MAP_TRANSFER_SOURCE      0x48 /* s32[1] source player id the ids mode collects (BeginMapTransferToTargetPlayer) */
#define MAP_TRANSFER_ENTRIES     0x4C /* u8 * received player entries, MAP_TRANSFER_SLOTS of them */
#define MAP_TRANSFER_RECORDS     0x50 /* u8 * expanded received map records */
#define MAP_TRANSFER_CHOSEN      0x54 /* u8 * received map record picked for play */
#define MAP_TRANSFER_SLOTS       10
#define MAP_TRANSFER_ENTRY_SIZE  0x310
#define MAP_TRANSFER_RECORD_SIZE 0x6F8

/* The downloaded-map panel sprite the transfer screen creates (class
 * gMapTransferPanelSpriteClass): the step it shows, the per-player campaign-map
 * page it lists and which players' pages are ready, and the received-record
 * buffers. */
#define MAP_TRANSFER_PANEL_STEP    0x34 /* u8 transfer step, 1..4 */
#define MAP_TRANSFER_PANEL_PAGE0   0x38 /* u8 *first player's campaign-map page */
#define MAP_TRANSFER_PANEL_PAGES   0x3C /* s32[4] each ready player's page pointer */
#define MAP_TRANSFER_PANEL_LOCAL   0x4C /* s8 local player id */
#define MAP_TRANSFER_PANEL_READY   0x4D /* u8 bit per player whose page is ready */
#define MAP_TRANSFER_PANEL_RECORDS 0x50 /* u8 * the local player's own five-map record list (MAP_RECORD_LIST_SIZE bytes) */
#define MAP_TRANSFER_PANEL_CHOSEN  0x54 /* u8 * the players' downloaded-map list, the same shape, received over the link */

/* The map-code entry panel (class gMapCodeEntryPanelVTable): the code-entry
 * screen that types a campaign map's code, built by CreateMapCodeEntryPanel.
 * Its destructor tears down three heap children. */
#define MAP_CODE_PANEL_ENTRY    0x34 /* s32 entry slot being edited */
#define MAP_CODE_PANEL_CURSOR   0x38 /* s8 cursor position in the code */
#define MAP_CODE_PANEL_X        0x3A /* s16 panel x, -0x8000 before it is placed */
#define MAP_CODE_PANEL_Y        0x3C /* s16 panel y, -0x8000 before it is placed */
#define MAP_CODE_PANEL_GRID     0x40 /* void *sprite-grid child; its +0x14 is the glyph heap block it owns */
#define MAP_CODE_PANEL_SUBPANEL 0x44 /* void *heap sub-panel child, freed through its own vtable */
#define MAP_CODE_PANEL_SPRITE   0x48 /* SpriteTween *: the panel's reveal tween, stepped by UpdateMapCodeEntryPanel */

/* The ov006 map-list screen object: the online map-trade screen that lists the
 * campaign maps it can join, and can show the player's own map code.  It keeps
 * the buffered player entries and, per candidate map, the player id, map id and
 * join result the list rows are built from. */
#define MAP_LIST_PLAYER_COUNT  0x34 /* s32 number of received player entries */
#define MAP_LIST_MAP_COUNT     0x38 /* u8 number of candidate map ids */
#define MAP_LIST_JOINABLE_COUNT 0x39 /* u8 number of maps found joinable (max 3) */
#define MAP_LIST_ROW_INDEX     0x3A /* u8 row the list builder is on */
#define MAP_LIST_DISPLAY_KIND  0x3B /* u8 code display kind, 0 when the list is shown */
#define MAP_LIST_CODE_LO       0x3C /* s32 low word of the 64-bit map code shown */
#define MAP_LIST_CODE_HI       0x40 /* s32 high word of the map code shown */
#define MAP_LIST_PLAYER_IDS    0x44 /* s32[10] player id of each list entry */
#define MAP_LIST_MAP_IDS       0x48 /* u16[10] campaign map id of each candidate */
#define MAP_LIST_STATUS        0x4C /* u8[10] per-candidate state: 1 joinable, 2 rejected */
#define MAP_LIST_JOINABLE_IDS  0x50 /* u16[3] map ids that can be joined */
#define MAP_LIST_ENTRIES       0x54 /* u8 *received player entries, PLAYER_ENTRY_SIZE each */
#define MAP_LIST_MAX_ENTRIES   10
#define MAP_LIST_MAX_JOINABLE  3
#define MAP_LIST_ENTRY_SIZE    0x310

/* Campaign map headers (gCampaignMapHeaders) are grouped in pages of this many
 * headers, one page per player on the transfer screen. */
#define CAMPAIGN_PAGE_HEADERS 50

/* The ov006 "offer this map" object (class data_ov006_02218a48) that searches
 * for another linked player to exchange the campaign map with: the map it
 * offers, the text buffer the search request is named with, how many players
 * the search found and the map record it sends them. */
#define MAP_OFFER_MAP_ID       0x34 /* s32 campaign map id offered */
#define MAP_OFFER_PLAYER_COUNT 0x38 /* s32 players the current request found */
#define MAP_OFFER_NAME         0x3C /* void *text buffer holding the map name */
#define MAP_OFFER_TIMEOUT      0x40 /* s32 match-request timeout result */
#define MAP_OFFER_FLAGS        0x44 /* s32 match-request result flags */
#define MAP_OFFER_RECORD       0x48 /* void *map record buffer, MAP_OFFER_RECORD_SIZE bytes */
#define MAP_OFFER_PACKED       0x4C /* void *packed map record, MAP_OFFER_PACKED_SIZE bytes */
#define MAP_OFFER_RECORD_SIZE 0x6F8
#define MAP_OFFER_PACKED_SIZE 0x2AC

/* The map-offer search state the whole overlay shares: the player-record buffer
 * the search receives into (one PLAYER_ENTRY_* record), whether a valid record
 * arrived, and whether the search has finished. */
#define MAP_OFFER_STATE_RECEIVED 0x00 /* u8: a valid player record arrived */
#define MAP_OFFER_STATE_RECORD   0x04 /* void *player-record buffer */
#define MAP_OFFER_STATE_DONE     0x08 /* s32: the search has finished */
extern M2C_UNK gMapOfferState;

/* A received player record (0x310 bytes, as created by
 * CreateOnlinePlayerListNode) carrying the player's map data. */
#define PLAYER_ENTRY_SIZE     0x310  /* bytes of one received player record */
#define PLAYER_ENTRY_ID       0x04   /* s32 player id, 0 when the record is empty */
#define PLAYER_ENTRY_DATA_LEN 0x30C  /* s32 bytes of map data at +0x10 */
#define PLAYER_ENTRY_SIZE     0x310  /* bytes of one received player record */

/* Status texts of the map-offer search. */
#define MAP_OFFER_MSG_PLAYER_FOUND 0x46000017
#define MAP_OFFER_MSG_NO_PLAYER    0x46000016

/* Status text shown above the name of the map chosen in a transfer. */
#define MAP_TRANSFER_MSG_CHOSEN_MAP 0x4600001F

/* The one-time hint the campaign map menu shows when it first opens, and the
 * event flag (index into gEventFlagsMid, see EVENT_FLAG_MID_BASE) that records
 * the hint has been shown. */
#define CAMPAIGN_MENU_MSG_HINT   0x46000026
#define CAMPAIGN_MENU_HINT_FLAG  0x21

/* The one-time hints the two map-pick lists (MENU_KIND_MAP_PICK_7/8) show when
 * they first open their ov006 map sub-panel, and the mid event flags that record
 * each hint has been shown.  Each hint creates one sprite from
 * gMapPickHintClass. */
#define MAP_PICK_HINT_MSG_7  0x46000028
#define MAP_PICK_HINT_FLAG_7 0x23
#define MAP_PICK_HINT_MSG_8  0x46000027
#define MAP_PICK_HINT_FLAG_8 0x22

#endif
