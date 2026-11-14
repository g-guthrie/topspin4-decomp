/* Swing_DLL.xex 0x885EE388-0x885EE408, executable version 0.0.0.3. */
typedef struct Ts4Bone {
    char pad[0x30];
    struct Ts4Bone **children;
    int count;
} Ts4Bone;
extern void fn_885EE388(Ts4Bone *bone, int index, float scale);
void ts4_scale_bone_tree_885EE388(Ts4Bone *bone, int index, float scale)
{
    float *weights = (float *)bone;
    int i;
    {float w = weights[index]; weights[index] = w * scale;}
    *(unsigned short *)((char *)bone + (index + 0x10) * 2) = 0;
    for (i = 0; i < bone->count; i++) {
        fn_885EE388(bone->children[i], index, scale);
    }
}
