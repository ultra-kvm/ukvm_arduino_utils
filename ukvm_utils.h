#ifndef UTILS_H
#define UTILS_H

class UTILS {
private:
public:
  static float mapFloat(float value, float aMin, float aMax, float bMin, float bMax){
      return (value - aMin) * (bMax - bMin) / (aMax - aMin) + bMin;
  }

  static int mapInt(int value, int aMin, int aMax, int bMin, int bMax){
      return round((float)(value - aMin) * (bMax - bMin) / (float)(aMax - aMin) + (float)bMin);
  }

  static String parseStr(String str, unsigned int idx, String delimiter = ","){
    if (idx == 0) return str.substring(0, str.indexOf(delimiter));

    int partIdx = 0;
    int partPos[10] = {0,0,0,0,0,0,0,0,0,0};
    for (int i = 0; i < str.length(); i++){
      if (str[i] == delimiter[0]){
        partIdx++;
        partPos[partIdx] = i;
      }
    }

    if (partIdx < idx) return "<out of bounds>";

    partPos[partIdx + 1] = str.length();

    return str.substring(partPos[idx] + 1, partPos[idx + 1]);
  }

  int tryParseInt(String str, int _default = 0){
    for (byte i = 0; i < str.length(); i++) if(!isDigit(str.charAt(i))) return _default;
    return atoi(str.c_str());
  }
};

#endif // UTILS_H