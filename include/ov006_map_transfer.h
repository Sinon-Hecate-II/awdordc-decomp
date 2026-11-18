/* The ov006 map-transfer screen: the object that exchanges campaign map records
 * between linked players, and the downloaded-map panel sprite it creates. */
#ifndef OV006_MAP_TRANSFER_H
#define OV006_MAP_TRANSFER_H

/* The ov006 map-transfer object: the campaign map id it exchanges, its transfer
 * mode, and the buffers it receives player entries (0x310 bytes each) and
 * expanded map records (0x6F8 bytes each) into. */
#define MAP_TRANSFER_MAP_ID      0x34 /* s32 campaign map id whose record is transferred */
#define MAP_TRANSFER_MODE        0x38 /* s32 transfer mode selecting the operation */
#define MAP_TRANSFER_COUNT       0x3C /* s32 number of player entries collected */
#define MAP_TRANSFER_SOURCE      0x48 /* s32 source map record for the local mode */
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
#define MAP_TRANSFER_PANEL_RECORDS 0x50 /* s32 received map-records buffer */
#define MAP_TRANSFER_PANEL_CHOSEN  0x54 /* s32 chosen received map record */

/* Campaign map headers (gCampaignMapHeaders) are grouped in pages of this many
 * headers, one page per player on the transfer screen. */
#define CAMPAIGN_PAGE_HEADERS 50

#endif
