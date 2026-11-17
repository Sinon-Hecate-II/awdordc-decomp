/* The scrolling sprite grid widget built by CreateSpriteGrid: a rows x columns
 * raster of fixed sprite cells that shows a window of the grid's items and
 * scrolls through them a row at a time, its pixel offset animating.  The cell
 * block is a fixed array of SpriteCell records stored as a SpriteCellList. */
#ifndef SPRITE_GRID_H
#define SPRITE_GRID_H

/* One cell of a sprite-cell block: the screen rectangle it covers and the
 * graphic it shows.  12 bytes; AddSpriteCell fills the first free cell. */
typedef struct SpriteCell {
    s16 x;      /* +0x00 screen x of the cell */
    s16 y;      /* +0x02 screen y of the cell */
    s16 width;  /* +0x04 cell width in pixels */
    s16 height; /* +0x06 cell height in pixels */
    u16 tile;   /* +0x08 graphic/tile index */
    u16 attr;   /* +0x0A attribute passed by the caller; 0 = cell is free */
} SpriteCell;

/* Fields of a fixed-capacity block of SpriteCell records. */
#define SPRITE_CELL_LIST_CAPACITY 0x10 /* u16 cells in the block */
#define SPRITE_CELL_LIST_USED     0x12 /* u8 cells filled */
#define SPRITE_CELL_LIST_CELLS    0x14 /* SpriteCell * the cells */

/* Fields the widget that owns the list adds: the box a touch must fall in for
 * the list to respond at all, and the tolerance added around each cell when a
 * point is tested against the cells (SpriteCellListBackgroundHit). */
#define SPRITE_CELL_LIST_BOX_LEFT   0x18 /* s16 left edge of the list's box */
#define SPRITE_CELL_LIST_BOX_TOP    0x1A /* s16 top edge of the list's box */
#define SPRITE_CELL_LIST_BOX_WIDTH  0x1C /* u16 width of the list's box */
#define SPRITE_CELL_LIST_BOX_HEIGHT 0x1E /* u16 height of the list's box */
#define SPRITE_CELL_LIST_HIT_PAD    0x20 /* u16 extra pixels around each cell */

/* Fields of the grid widget (CreateSpriteGrid), which embeds a cell list. */
#define SPRITE_GRID_VTABLE       0x00 /* void * class: gSpriteGridVTable */
#define SPRITE_GRID_ROWS         0x04 /* u8 rows of cells in the raster */
#define SPRITE_GRID_COLUMNS      0x05 /* u8 columns of cells in the raster */
#define SPRITE_GRID_CELL_WIDTH   0x06 /* u8 cell width in pixels */
#define SPRITE_GRID_CELL_HEIGHT  0x07 /* u8 cell height in pixels */
#define SPRITE_GRID_SELECTED     0x08 /* s16 item the cursor sits on */
#define SPRITE_GRID_ITEM_COUNT   0x0a /* s16 items the grid can scroll through */
#define SPRITE_GRID_SCROLL       0x0c /* s16 first visible row */
#define SPRITE_GRID_CURSOR_X     0x0e /* s16 screen x the cursor is drawn at (animated); -32768 before the first update */
#define SPRITE_GRID_CURSOR_Y     0x10 /* s16 screen y the cursor is drawn at (animated); -32768 before the first update */
#define SPRITE_GRID_PIXEL_OFFSET 0x12 /* s16 animated offset of the scroll, in pixels */
#define SPRITE_GRID_BASE_X       0x14 /* s16 screen x of the first cell */
#define SPRITE_GRID_BASE_Y       0x16 /* s16 screen y of the first cell */
#define SPRITE_GRID_CELLS        0x18 /* SpriteCellList embedded in the widget */

#endif
