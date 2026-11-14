/* Loader_DLL.xex 0x8316F538-0x8316F5C8 and three identical copies, executable version 0.0.0.3. */
void ts4l_hr_normalize_8316F538(long *p)
{
    long hr;
    hr = *p;
    if (hr == 0) {
        return;
    }
    if (hr == (long)0x8007000E) {
        return;
    }
    if (hr == (long)0x80004001) {
        return;
    }
    if ((short)(((hr) >> 16) & 0x1fff) == 0x896) {
        return;
    }
    switch (hr) {
    case (long)0x88780078:
    case (long)0x88780096:
    case (long)0x88880001:
        hr = (long)0x88960004;
        break;
    case (long)0x88970001:
        hr = (long)0x88960003;
        break;
    default:
        return;
    }
    *p = hr;
}

void ts4l_hr_normalize_83175078(long *p)
{
    long hr;
    hr = *p;
    if (hr == 0) {
        return;
    }
    if (hr == (long)0x8007000E) {
        return;
    }
    if (hr == (long)0x80004001) {
        return;
    }
    if ((short)(((hr) >> 16) & 0x1fff) == 0x896) {
        return;
    }
    switch (hr) {
    case (long)0x88780078:
    case (long)0x88780096:
    case (long)0x88880001:
        hr = (long)0x88960004;
        break;
    case (long)0x88970001:
        hr = (long)0x88960003;
        break;
    default:
        return;
    }
    *p = hr;
}

void ts4l_hr_normalize_8317F508(long *p)
{
    long hr;
    hr = *p;
    if (hr == 0) {
        return;
    }
    if (hr == (long)0x8007000E) {
        return;
    }
    if (hr == (long)0x80004001) {
        return;
    }
    if ((short)(((hr) >> 16) & 0x1fff) == 0x896) {
        return;
    }
    switch (hr) {
    case (long)0x88780078:
    case (long)0x88780096:
    case (long)0x88880001:
        hr = (long)0x88960004;
        break;
    case (long)0x88970001:
        hr = (long)0x88960003;
        break;
    default:
        return;
    }
    *p = hr;
}

void ts4l_hr_normalize_83189000(long *p)
{
    long hr;
    hr = *p;
    if (hr == 0) {
        return;
    }
    if (hr == (long)0x8007000E) {
        return;
    }
    if (hr == (long)0x80004001) {
        return;
    }
    if ((short)(((hr) >> 16) & 0x1fff) == 0x896) {
        return;
    }
    switch (hr) {
    case (long)0x88780078:
    case (long)0x88780096:
    case (long)0x88880001:
        hr = (long)0x88960004;
        break;
    case (long)0x88970001:
        hr = (long)0x88960003;
        break;
    default:
        return;
    }
    *p = hr;
}
