#include "common.h"

/* The overlay's area-effect scoring and score-combining callbacks. */
void *gAreaEffectCallbacks[2];

/* The next overlays start at the end of this 32-byte BSS block. */
u8 gAreaEffectBssPadding[24];
