#ifndef MAP_SELECTION_H
#define MAP_SELECTION_H

/* Map-data categories (MapData_GetCategory).  Every map id from
 * MAP_CUSTOM_FIRST to MAP_CUSTOM_LINK_END is the custom category; the other
 * categories come from the map record's category byte and are not named here.
 * MapListCategoryToDataCategory maps a map-list slot to one of these. */
#define MAP_DATA_CATEGORY_CUSTOM 6

/* A map category occupies 0x200 bytes; its last two bytes hold category and count. */
typedef struct MapSelectionCategory {
    u16 mapIds[255];
    u8 category;
    u8 count;
} MapSelectionCategory;

/* Twelve category slots followed by the number of populated slots. */
typedef struct MapSelectionLists {
    u8 entries[0x1800];
    u8 count;
} MapSelectionLists;

enum {
    MAP_LIST_CATEGORY_OFFSET = 0x1fe,
    MAP_LIST_COUNT_OFFSET = 0x1ff,
    MAP_LIST_CUSTOM = 7,
    MAP_LIST_LINK_CUSTOM_FIRST = 8,
    MAP_LIST_CATEGORY_END = 12,
    MAP_CUSTOM_FIRST = 225,
    MAP_CUSTOM_LOCAL_END = 275,
    MAP_CUSTOM_LINK_END = 425
};

#endif
