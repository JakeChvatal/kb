// vararg macro -- delays macro expansion for home rows
#define planck_layout(...) LAYOUT_planck_grid(__VA_ARGS__)

// helpful macros for laying out key groups
#ifdef WIDE_LAYOUT
#define flex_planck_layout(BL1, L1, R1, BR1, \
                           BL2, L2, R2, BR2, \
                           BL3, L3, R3, BR3, \
                           BL4, L4, R4, BR4) \
    planck_layout( \
      L1, BL1, BR1, R1, \
      L2, BL2, BR2, R2, \
      L3, BL3, BR3, R3, \
      L4, BL4, BR4, R4  \
    )

#else
#define flex_planck_layout(BL1, L1, R1, BR1, \
                           BL2, L2, R2, BR2, \
                           BL3, L3, R3, BR3, \
                           BL4, L4, R4, BR4) \
    planck_layout( \
      BL1, L1, R1, BR1, \
      BL2, L2, R2, BR2, \
      BL3, L3, R3, BR3, \
      BL4, L4, R4, BR4 \
    )
#endif
