//
// Created by Erick on 10/27/2020.
//

#include "HitBox.h"

HitBox::HitBox() {
    x = 0;
    y = 0;
    width = 0;
    height = 0;
}

HitBox::HitBox(HitBox &hitBox) {
    x = hitBox.getX();
    y = hitBox.getY();
    width = hitBox.getWidth();
    height = hitBox.getHeight();
}

HitBox::HitBox(int x, int y, Dimension &dimension) {
    HitBox::x = x;
    HitBox::y = y;
    width = dimension.getWidth();
    height = dimension.getHeight();
}

HitBox::HitBox(Point &point, Dimension &dimension) {
    x = point.getX();
    y = point.getY();
    width = dimension.getWidth();
    height = dimension.getHeight();
}

HitBox::HitBox(int x, int y, int width, int height) {
    HitBox::x = x;
    HitBox::y = y;
    HitBox::width = width;
    HitBox::height = height;
}

HitBox::HitBox(Point &point, int width, int height) {
    x = point.getX();
    y = point.getY();
    HitBox::width = width;
    HitBox::height = height;
}

int HitBox::getX() const {
    return x;
}

void HitBox::setX(int x) {
    HitBox::x = x;
}

int HitBox::getY() const {
    return y;
}

void HitBox::setY(int y) {
    HitBox::y = y;
}

int HitBox::getWidth() const {
    return width;
}

void HitBox::setWidth(int width) {
    HitBox::width = width;
}

int HitBox::getHeight() const {
    return height;
}

void HitBox::setHeight(int height) {
    HitBox::height = height;
}

bool HitBox::contains(Point point, Dimension dimension) {
    return contains(point.getX(),point.getY(),dimension.getWidth(),dimension.getHeight());
}

bool HitBox::contains(int X, int Y, int W, int H) {
    int w = HitBox::width;
    int h = HitBox::height;
    if ((w | h | W | H) < 0) {
        return false;
    }
    int x = HitBox::x;
    int y = HitBox::y;
    if (X < x || Y < y) {
        return false;
    }
    w += x;
    W += X;
    if (W <= X) {
        if (w >= x || W > w) return false;
    } else {
        if (w >= x && W > w) return false;
    }
    h += y;
    H += Y;
    if (H <= Y) {
        if (h >= y || H > h) return false;
    } else {
        if (h >= y && H > h) return false;
    }
    return true;
}

int HitBox::outcode(double x, double y) const {
    /*
     * Note on casts to double below.  If the arithmetic of
     * x+w or y+h is done in int, then we may get integer
     * overflow. By converting to double before the addition
     * we force the addition to be carried out in double to
     * avoid overflow in the comparison.
     *
     * See bug 4320890 for problems that this can cause.
     */
    int out = 0;
    if (width <= 0) {
        out |= 1 | 4;
    } else if (x < this->x) {
        out |= 1;
    } else if (x > this->x + (double) this->width) {
        out |= 4;
    }
    if (this->height <= 0) {
        out |= 2 | 8;
    } else if (y < this->y) {
        out |= 2;
    } else if (y > this->y + (double) this->height) {
        out |= 8;
    }
    return out;
}

bool HitBox::intersects(const HitBox &hitBox) const {
    int tw = HitBox::width;
    int th = HitBox::height;
    int rw = hitBox.getWidth();
    int rh = hitBox.getHeight();
    if (rw <= 0 || rh <= 0 || tw <= 0 || th <= 0) {
        return false;
    }
    int tx = HitBox::x;
    int ty = HitBox::y;
    int rx = hitBox.getX();
    int ry = hitBox.getY();
    rw += rx;
    rh += ry;
    tw += tx;
    th += ty;
    return ((rw < rx || rw > tx) &&
            (rh < ry || rh > ty) &&
            (tw < tx || tw > rx) &&
            (th < ty || th > ry));
}

string HitBox::toString() {
    return "x: " + to_string(x) + ", y: " + to_string(y) + ", width: " + to_string(width) + ", height: " + to_string(height);
}

void HitBox::setSize(int width, int height) {
    width = width;
    height = height;
}

void HitBox::setSize(Dimension dimension) {
    width = dimension.getWidth();
    height = dimension.getHeight();
}

Dimension HitBox::getSize() {
    return Dimension(width,height);
}

int HitBox::getCenterX() {
    return x+(width/2);
}

int HitBox::getCenterY() {
    return y+(height/2);
}

int HitBox::getMinX() const {
    return x;
}

int HitBox::getMaxX() const {
    return x+width;
}

int HitBox::getMinY() const {
    return y;
}

int HitBox::getMaxY() const {
    return y+height;
}

void HitBox::setBounds(int x, int y, int width, int height) {
    HitBox::x = x;
    HitBox::y = y;
    HitBox::width = width;
    HitBox::height = height;
}

void HitBox::setBounds(HitBox &hitBox) {
    x = hitBox.x;
    y = hitBox.y;
    width = hitBox.width;
    height = hitBox.height;
}


