#include "hue.h"

uint16_t rgb565_from_hue(float hue) {
    float r, g, b;
    int i;
    float f, p, q, t;

    // hue 值范围: [0, 1)
    hue = hue * 6;  // 将 hue 值放大到 [0, 6)
    i = (int)hue;   // 取整，得到所在的区间
    f = hue - i;    // 小数部分，用于计算平滑过渡

    p = 0;
    q = 1 - f;
    t = f;

    switch (i % 6) {
        case 0: r = 1; g = t; b = p; break; // 红色到黄色的过渡
        case 1: r = q; g = 1; b = p; break; // 黄色到绿色的过渡
        case 2: r = p; g = 1; b = t; break; // 绿色到青色的过渡
        case 3: r = p; g = q; b = 1; break; // 青色到蓝色的过渡
        case 4: r = t; g = p; b = 1; break; // 蓝色到紫色的过渡
        case 5: r = 1; g = p; b = q; break; // 紫色到红色的过渡
    }

    // 将 RGB 浮点数值转换为 5 位红色，6 位绿色，5 位蓝色
    uint8_t r5 = (uint8_t)(r * 31);  // 5位红色
    uint8_t g6 = (uint8_t)(g * 63);  // 6位绿色
    uint8_t b5 = (uint8_t)(b * 31);  // 5位蓝色

    // 组合为 RGB565 格式的 16 位数值
    uint16_t color565 = (r5 << 11) | (g6 << 5) | b5;

    return color565;
}
