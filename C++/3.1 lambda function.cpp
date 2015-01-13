int lambaste = 100;

auto lame = [](int x){return x * x;};   // okay

auto lamebrain = [=](int x){return lambaste * x;};  // use lambaste outside

auto lamebrain = [&](int x){return lambaste * x;}; // use reference of lambaste outside

