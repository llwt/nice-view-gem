#include <stdlib.h>
#include <zephyr/kernel.h>
#include "animation.h"

#if IS_ENABLED(CONFIG_NICE_VIEW_GEM_ART_CRYSTAL)

LV_IMG_DECLARE(crystal_01);
LV_IMG_DECLARE(crystal_02);
LV_IMG_DECLARE(crystal_03);
LV_IMG_DECLARE(crystal_04);
LV_IMG_DECLARE(crystal_05);
LV_IMG_DECLARE(crystal_06);
LV_IMG_DECLARE(crystal_07);
LV_IMG_DECLARE(crystal_08);
LV_IMG_DECLARE(crystal_09);
LV_IMG_DECLARE(crystal_10);
LV_IMG_DECLARE(crystal_11);
LV_IMG_DECLARE(crystal_12);
LV_IMG_DECLARE(crystal_13);
LV_IMG_DECLARE(crystal_14);
LV_IMG_DECLARE(crystal_15);
LV_IMG_DECLARE(crystal_16);

const lv_img_dsc_t *anim_imgs[] = {
    &crystal_01, &crystal_02, &crystal_03, &crystal_04, &crystal_05, &crystal_06,
    &crystal_07, &crystal_08, &crystal_09, &crystal_10, &crystal_11, &crystal_12,
    &crystal_13, &crystal_14, &crystal_15, &crystal_16,
};

#define ANIM_IMG_COUNT 16
#define ANIM_X_OFFSET 36

#else /* CONFIG_NICE_VIEW_GEM_ART_SLIDESHOW */

LV_IMG_DECLARE(hammerbeam1);
LV_IMG_DECLARE(hammerbeam2);
LV_IMG_DECLARE(hammerbeam3);
LV_IMG_DECLARE(hammerbeam4);
LV_IMG_DECLARE(hammerbeam5);
LV_IMG_DECLARE(hammerbeam6);
LV_IMG_DECLARE(hammerbeam7);
LV_IMG_DECLARE(hammerbeam8);
LV_IMG_DECLARE(hammerbeam9);
LV_IMG_DECLARE(hammerbeam10);
LV_IMG_DECLARE(hammerbeam11);
LV_IMG_DECLARE(hammerbeam12);
LV_IMG_DECLARE(hammerbeam13);
LV_IMG_DECLARE(hammerbeam14);
LV_IMG_DECLARE(hammerbeam15);
LV_IMG_DECLARE(hammerbeam16);
LV_IMG_DECLARE(hammerbeam17);
LV_IMG_DECLARE(hammerbeam18);
LV_IMG_DECLARE(hammerbeam19);
LV_IMG_DECLARE(hammerbeam20);
LV_IMG_DECLARE(hammerbeam21);
LV_IMG_DECLARE(hammerbeam22);
LV_IMG_DECLARE(hammerbeam23);
LV_IMG_DECLARE(hammerbeam24);
LV_IMG_DECLARE(hammerbeam25);
LV_IMG_DECLARE(hammerbeam26);
LV_IMG_DECLARE(hammerbeam27);
LV_IMG_DECLARE(hammerbeam28);
LV_IMG_DECLARE(hammerbeam29);
LV_IMG_DECLARE(hammerbeam30);

const lv_img_dsc_t *anim_imgs[] = {
    &hammerbeam1,  &hammerbeam2,  &hammerbeam3,  &hammerbeam4,  &hammerbeam5,
    &hammerbeam6,  &hammerbeam7,  &hammerbeam8,  &hammerbeam9,  &hammerbeam10,
    &hammerbeam11, &hammerbeam12, &hammerbeam13, &hammerbeam14, &hammerbeam15,
    &hammerbeam16, &hammerbeam17, &hammerbeam18, &hammerbeam19, &hammerbeam20,
    &hammerbeam21, &hammerbeam22, &hammerbeam23, &hammerbeam24, &hammerbeam25,
    &hammerbeam26, &hammerbeam27, &hammerbeam28, &hammerbeam29, &hammerbeam30,
};

#define ANIM_IMG_COUNT 30
#define ANIM_X_OFFSET 0

#endif

void draw_animation(lv_obj_t *canvas) {
#if IS_ENABLED(CONFIG_NICE_VIEW_GEM_ANIMATION)
    lv_obj_t *art = lv_animimg_create(canvas);
    lv_obj_center(art);

    lv_animimg_set_src(art, (const void **)anim_imgs, ANIM_IMG_COUNT);
    lv_animimg_set_duration(art, CONFIG_NICE_VIEW_GEM_ANIMATION_MS);
    lv_animimg_set_repeat_count(art, LV_ANIM_REPEAT_INFINITE);
    lv_animimg_start(art);
#else
    lv_obj_t *art = lv_img_create(canvas);

    int length = sizeof(anim_imgs) / sizeof(anim_imgs[0]);
    srand(k_uptime_get_32());
    int random_index = rand() % length;

    lv_img_set_src(art, anim_imgs[random_index]);
#endif

    lv_obj_align(art, LV_ALIGN_TOP_LEFT, ANIM_X_OFFSET, 0);
}
