#include <map>
#include <vector>

#include "gtest/gtest.h"
#include "src/lib/trojanmap.h"

TEST(TrojanMapTest, Autocomplete) {
  TrojanMap m;
  m.CreateGraphFromCSVFile();
  // Test the simple case
  auto names = m.Autocomplete("l");
  std::unordered_set<std::string> gt1 = {"Lawn", "LATTCOrtho Institute","Little Galen Center","Leavey Library","Los Angeles Orthopaedic Hospital","Los Angeles","LycaMobile","Lyons Center"}; // groundtruth for "Ch"
  int success = 0;
  for (auto& n: names) {
    EXPECT_EQ(gt1.count(n) > 0, true);
    if (gt1.count(n) > 0){
      success++;
    }
  }

