#include "hue.h"

uint16_t rgb565_from_hue(float hue) {
    float r, g, b;
    int i;
    float f, p, q, t;

    // hue ֵ��Χ: [0, 1)
    hue = hue * 6;  // �� hue ֵ�Ŵ� [0, 6)
    i = (int)hue;   // ȡ�����õ����ڵ�����
    f = hue - i;    // С�����֣����ڼ���ƽ������

    p = 0;
    q = 1 - f;
    t = f;

    switch (i % 6) {
        case 0: r = 1; g = t; b = p; break; // ��ɫ����ɫ�Ĺ���
        case 1: r = q; g = 1; b = p; break; // ��ɫ����ɫ�Ĺ���
        case 2: r = p; g = 1; b = t; break; // ��ɫ����ɫ�Ĺ���
        case 3: r = p; g = q; b = 1; break; // ��ɫ����ɫ�Ĺ���
        case 4: r = t; g = p; b = 1; break; // ��ɫ����ɫ�Ĺ���
        case 5: r = 1; g = p; b = q; break; // ��ɫ����ɫ�Ĺ���
    }

    // �� RGB ������ֵת��Ϊ 5 λ��ɫ��6 λ��ɫ��5 λ��ɫ
    uint8_t r5 = (uint8_t)(r * 31);  // 5λ��ɫ
    uint8_t g6 = (uint8_t)(g * 63);  // 6λ��ɫ
    uint8_t b5 = (uint8_t)(b * 31);  // 5λ��ɫ

    // ���Ϊ RGB565 ��ʽ�� 16 λ��ֵ
    uint16_t color565 = (r5 << 11) | (g6 << 5) | b5;

    return color565;
}
