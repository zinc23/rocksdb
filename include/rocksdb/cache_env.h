#pragma once

#include "rocksdb/env.h"

namespace rocksdb {

//
// Direct IO Env implementation for *nix operating system variants
//
class DirectIOEnv : public EnvWrapper {
public:
  explicit DirectIOEnv(Env* env, const bool direct_read = true,
                       const bool direct_writes = true);

  virtual ~DirectIOEnv() {}

  virtual Status NewSequentialFile(const std::string& fname,
                                   unique_ptr<SequentialFile>* result,
                                   const EnvOptions& options);

  virtual Status NewRandomAccessFile(const std::string& fname,
                                     unique_ptr<RandomAccessFile>* result,
                                     const EnvOptions& options);

  virtual Status NewWritableFile(const std::string& fname,
                                 unique_ptr<WritableFile>* result,
                                 const EnvOptions& options);
private:
  const bool direct_read_ = true;
  const bool direct_writes_ = true;
};

}
