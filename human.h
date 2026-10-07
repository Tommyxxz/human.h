/*
 * Copyright (c) 2026 Xinzhe Xiao
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * File Name: huamn.h
 * Author: Xinzhe Xiao
 * Created: 2026-10-06
 * Version: 0.1 (Preview version)
 */

#include<bits/stdc++.h>
using namespace std;
int foodmax,tiredmax,moneystart;

struct human {
    bool alive=false;
    int age=0;
    int food=foodmax,tired=0;
    int money=moneystart;
};

void born(human &x) {
    x.alive=true;
}
bool grow(human &x,int y) {
    if(x.alive) {
        x.age+=y;
        return true;
    }
    else {
        return false;
    }
}
void die(human &x) {
    x.alive=false;
}

bool eat(human &x,int y) {
    if(x.alive) {
        x.food=min(foodmax,x.food+y);
        return true;
    }
    else {
        return false;
    }
}
bool sleep(human &x,int y) {
    if(x.alive) {
        x.tired=max(0,x.tired-y);
        return true;
    }
    else {
        return false;
    }
}
bool earn_money(human &x,int y) {
    if(x.alive) {
        x.money+=y;
        return true;
    }
    else {
        return false;
    }
}

bool get_hungry(human &x,int y) {
    if(x.alive) {
        if(x.food-y<0) {
            die(x);
        }
        else {
            x.food-=y;
        }
        return true;
    }
    else {
        return false;
    }
}
bool get_tired(human &x,int y) {
    if(x.alive) {
        if(x.tired+y>tiredmax) {
            die(x);
        }
        else {
            x.tired+=y;
        }
        return true;
    }
    else {
        return false;
    }
}
bool lose_money(human &x,int y) {
    if(x.alive) {
        x.money=min(0,x.money-y);
        return true;
    }
    else {
        return false;
    }
}