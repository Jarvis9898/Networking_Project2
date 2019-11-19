// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: addressbook.proto

#include "addressbook.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
extern PROTOBUF_INTERNAL_EXPORT_addressbook_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_Person_addressbook_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_addressbook_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_Person_PhoneNumber_addressbook_2eproto;
namespace example {
class Person_PhoneNumberDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<Person_PhoneNumber> _instance;
} _Person_PhoneNumber_default_instance_;
class PersonDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<Person> _instance;
} _Person_default_instance_;
class AddressBookDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<AddressBook> _instance;
} _AddressBook_default_instance_;
}  // namespace example
static void InitDefaultsscc_info_AddressBook_addressbook_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::example::_AddressBook_default_instance_;
    new (ptr) ::example::AddressBook();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::example::AddressBook::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_AddressBook_addressbook_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_AddressBook_addressbook_2eproto}, {
      &scc_info_Person_addressbook_2eproto.base,}};

static void InitDefaultsscc_info_Person_addressbook_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::example::_Person_default_instance_;
    new (ptr) ::example::Person();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::example::Person::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_Person_addressbook_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_Person_addressbook_2eproto}, {
      &scc_info_Person_PhoneNumber_addressbook_2eproto.base,}};

static void InitDefaultsscc_info_Person_PhoneNumber_addressbook_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::example::_Person_PhoneNumber_default_instance_;
    new (ptr) ::example::Person_PhoneNumber();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::example::Person_PhoneNumber::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_Person_PhoneNumber_addressbook_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_Person_PhoneNumber_addressbook_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_addressbook_2eproto[3];
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_addressbook_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_addressbook_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_addressbook_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::example::Person_PhoneNumber, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::example::Person_PhoneNumber, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::example::Person_PhoneNumber, number_),
  PROTOBUF_FIELD_OFFSET(::example::Person_PhoneNumber, type_),
  0,
  1,
  PROTOBUF_FIELD_OFFSET(::example::Person, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::example::Person, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::example::Person, name_),
  PROTOBUF_FIELD_OFFSET(::example::Person, id_),
  PROTOBUF_FIELD_OFFSET(::example::Person, email_),
  PROTOBUF_FIELD_OFFSET(::example::Person, phones_),
  0,
  2,
  1,
  ~0u,
  PROTOBUF_FIELD_OFFSET(::example::AddressBook, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::example::AddressBook, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::example::AddressBook, people_),
  ~0u,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 7, sizeof(::example::Person_PhoneNumber)},
  { 9, 18, sizeof(::example::Person)},
  { 22, 28, sizeof(::example::AddressBook)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::example::_Person_PhoneNumber_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::example::_Person_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::example::_AddressBook_default_instance_),
};

const char descriptor_table_protodef_addressbook_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\021addressbook.proto\022\007example\"\331\001\n\006Person\022"
  "\014\n\004name\030\001 \002(\t\022\n\n\002id\030\002 \002(\005\022\r\n\005email\030\003 \001(\t"
  "\022+\n\006phones\030\004 \003(\0132\033.example.Person.PhoneN"
  "umber\032L\n\013PhoneNumber\022\016\n\006number\030\001 \002(\t\022-\n\004"
  "type\030\002 \001(\0162\031.example.Person.PhoneType:\004H"
  "OME\"+\n\tPhoneType\022\n\n\006MOBILE\020\000\022\010\n\004HOME\020\001\022\010"
  "\n\004WORK\020\002\".\n\013AddressBook\022\037\n\006people\030\001 \003(\0132"
  "\017.example.Person"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_addressbook_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_addressbook_2eproto_sccs[3] = {
  &scc_info_AddressBook_addressbook_2eproto.base,
  &scc_info_Person_addressbook_2eproto.base,
  &scc_info_Person_PhoneNumber_addressbook_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_addressbook_2eproto_once;
static bool descriptor_table_addressbook_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_addressbook_2eproto = {
  &descriptor_table_addressbook_2eproto_initialized, descriptor_table_protodef_addressbook_2eproto, "addressbook.proto", 296,
  &descriptor_table_addressbook_2eproto_once, descriptor_table_addressbook_2eproto_sccs, descriptor_table_addressbook_2eproto_deps, 3, 0,
  schemas, file_default_instances, TableStruct_addressbook_2eproto::offsets,
  file_level_metadata_addressbook_2eproto, 3, file_level_enum_descriptors_addressbook_2eproto, file_level_service_descriptors_addressbook_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_addressbook_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_addressbook_2eproto), true);
namespace example {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Person_PhoneType_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_addressbook_2eproto);
  return file_level_enum_descriptors_addressbook_2eproto[0];
}
bool Person_PhoneType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

#if (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)
constexpr Person_PhoneType Person::MOBILE;
constexpr Person_PhoneType Person::HOME;
constexpr Person_PhoneType Person::WORK;
constexpr Person_PhoneType Person::PhoneType_MIN;
constexpr Person_PhoneType Person::PhoneType_MAX;
constexpr int Person::PhoneType_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)

// ===================================================================

void Person_PhoneNumber::InitAsDefaultInstance() {
}
class Person_PhoneNumber::_Internal {
 public:
  using HasBits = decltype(std::declval<Person_PhoneNumber>()._has_bits_);
  static void set_has_number(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_type(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
};

Person_PhoneNumber::Person_PhoneNumber()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:example.Person.PhoneNumber)
}
Person_PhoneNumber::Person_PhoneNumber(const Person_PhoneNumber& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  number_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_number()) {
    number_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.number_);
  }
  type_ = from.type_;
  // @@protoc_insertion_point(copy_constructor:example.Person.PhoneNumber)
}

void Person_PhoneNumber::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_Person_PhoneNumber_addressbook_2eproto.base);
  number_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  type_ = 1;
}

Person_PhoneNumber::~Person_PhoneNumber() {
  // @@protoc_insertion_point(destructor:example.Person.PhoneNumber)
  SharedDtor();
}

void Person_PhoneNumber::SharedDtor() {
  number_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void Person_PhoneNumber::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const Person_PhoneNumber& Person_PhoneNumber::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_Person_PhoneNumber_addressbook_2eproto.base);
  return *internal_default_instance();
}


void Person_PhoneNumber::Clear() {
// @@protoc_insertion_point(message_clear_start:example.Person.PhoneNumber)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      number_.ClearNonDefaultToEmptyNoArena();
    }
    type_ = 1;
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* Person_PhoneNumber::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // required string number = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParserUTF8Verify(_internal_mutable_number(), ptr, ctx, "example.Person.PhoneNumber.number");
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional .example.Person.PhoneType type = 2 [default = HOME];
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
          if (PROTOBUF_PREDICT_TRUE(::example::Person_PhoneType_IsValid(val))) {
            _internal_set_type(static_cast<::example::Person_PhoneType>(val));
          } else {
            ::PROTOBUF_NAMESPACE_ID::internal::WriteVarint(2, val, mutable_unknown_fields());
          }
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Person_PhoneNumber::InternalSerializeWithCachedSizesToArray(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:example.Person.PhoneNumber)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required string number = 1;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_number().data(), static_cast<int>(this->_internal_number().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "example.Person.PhoneNumber.number");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_number(), target);
  }

  // optional .example.Person.PhoneType type = 2 [default = HOME];
  if (cached_has_bits & 0x00000002u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      2, this->_internal_type(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:example.Person.PhoneNumber)
  return target;
}

size_t Person_PhoneNumber::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:example.Person.PhoneNumber)
  size_t total_size = 0;

  // required string number = 1;
  if (has_number()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_number());
  }
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // optional .example.Person.PhoneType type = 2 [default = HOME];
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000002u) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_type());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Person_PhoneNumber::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:example.Person.PhoneNumber)
  GOOGLE_DCHECK_NE(&from, this);
  const Person_PhoneNumber* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Person_PhoneNumber>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:example.Person.PhoneNumber)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:example.Person.PhoneNumber)
    MergeFrom(*source);
  }
}

void Person_PhoneNumber::MergeFrom(const Person_PhoneNumber& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:example.Person.PhoneNumber)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      _has_bits_[0] |= 0x00000001u;
      number_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.number_);
    }
    if (cached_has_bits & 0x00000002u) {
      type_ = from.type_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void Person_PhoneNumber::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:example.Person.PhoneNumber)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Person_PhoneNumber::CopyFrom(const Person_PhoneNumber& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:example.Person.PhoneNumber)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Person_PhoneNumber::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;
  return true;
}

void Person_PhoneNumber::InternalSwap(Person_PhoneNumber* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  number_.Swap(&other->number_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(type_, other->type_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Person_PhoneNumber::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void Person::InitAsDefaultInstance() {
}
class Person::_Internal {
 public:
  using HasBits = decltype(std::declval<Person>()._has_bits_);
  static void set_has_name(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_id(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static void set_has_email(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
};

Person::Person()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:example.Person)
}
Person::Person(const Person& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_),
      phones_(from.phones_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_name()) {
    name_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.name_);
  }
  email_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_email()) {
    email_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.email_);
  }
  id_ = from.id_;
  // @@protoc_insertion_point(copy_constructor:example.Person)
}

void Person::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_Person_addressbook_2eproto.base);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  email_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  id_ = 0;
}

Person::~Person() {
  // @@protoc_insertion_point(destructor:example.Person)
  SharedDtor();
}

void Person::SharedDtor() {
  name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  email_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void Person::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const Person& Person::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_Person_addressbook_2eproto.base);
  return *internal_default_instance();
}


void Person::Clear() {
// @@protoc_insertion_point(message_clear_start:example.Person)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  phones_.Clear();
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      name_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000002u) {
      email_.ClearNonDefaultToEmptyNoArena();
    }
  }
  id_ = 0;
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* Person::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // required string name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParserUTF8Verify(_internal_mutable_name(), ptr, ctx, "example.Person.name");
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required int32 id = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          _Internal::set_has_id(&has_bits);
          id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional string email = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParserUTF8Verify(_internal_mutable_email(), ptr, ctx, "example.Person.email");
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated .example.Person.PhoneNumber phones = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_phones(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<34>(ptr));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Person::InternalSerializeWithCachedSizesToArray(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:example.Person)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required string name = 1;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_name().data(), static_cast<int>(this->_internal_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "example.Person.name");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_name(), target);
  }

  // required int32 id = 2;
  if (cached_has_bits & 0x00000004u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(2, this->_internal_id(), target);
  }

  // optional string email = 3;
  if (cached_has_bits & 0x00000002u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_email().data(), static_cast<int>(this->_internal_email().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "example.Person.email");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_email(), target);
  }

  // repeated .example.Person.PhoneNumber phones = 4;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_phones_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessageToArray(4, this->_internal_phones(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:example.Person)
  return target;
}

size_t Person::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:example.Person)
  size_t total_size = 0;

  if (has_name()) {
    // required string name = 1;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());
  }

  if (has_id()) {
    // required int32 id = 2;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_id());
  }

  return total_size;
}
size_t Person::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:example.Person)
  size_t total_size = 0;

  if (((_has_bits_[0] & 0x00000005) ^ 0x00000005) == 0) {  // All required fields are present.
    // required string name = 1;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());

    // required int32 id = 2;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_id());

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .example.Person.PhoneNumber phones = 4;
  total_size += 1UL * this->_internal_phones_size();
  for (const auto& msg : this->phones_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // optional string email = 3;
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000002u) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_email());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Person::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:example.Person)
  GOOGLE_DCHECK_NE(&from, this);
  const Person* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Person>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:example.Person)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:example.Person)
    MergeFrom(*source);
  }
}

void Person::MergeFrom(const Person& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:example.Person)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  phones_.MergeFrom(from.phones_);
  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    if (cached_has_bits & 0x00000001u) {
      _has_bits_[0] |= 0x00000001u;
      name_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.name_);
    }
    if (cached_has_bits & 0x00000002u) {
      _has_bits_[0] |= 0x00000002u;
      email_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.email_);
    }
    if (cached_has_bits & 0x00000004u) {
      id_ = from.id_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void Person::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:example.Person)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Person::CopyFrom(const Person& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:example.Person)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Person::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000005) != 0x00000005) return false;
  if (!::PROTOBUF_NAMESPACE_ID::internal::AllAreInitialized(this->phones())) return false;
  return true;
}

void Person::InternalSwap(Person* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  phones_.InternalSwap(&other->phones_);
  name_.Swap(&other->name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  email_.Swap(&other->email_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(id_, other->id_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Person::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void AddressBook::InitAsDefaultInstance() {
}
class AddressBook::_Internal {
 public:
  using HasBits = decltype(std::declval<AddressBook>()._has_bits_);
};

AddressBook::AddressBook()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:example.AddressBook)
}
AddressBook::AddressBook(const AddressBook& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_),
      people_(from.people_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:example.AddressBook)
}

void AddressBook::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_AddressBook_addressbook_2eproto.base);
}

AddressBook::~AddressBook() {
  // @@protoc_insertion_point(destructor:example.AddressBook)
  SharedDtor();
}

void AddressBook::SharedDtor() {
}

void AddressBook::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const AddressBook& AddressBook::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_AddressBook_addressbook_2eproto.base);
  return *internal_default_instance();
}


void AddressBook::Clear() {
// @@protoc_insertion_point(message_clear_start:example.AddressBook)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  people_.Clear();
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* AddressBook::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // repeated .example.Person people = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_people(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<10>(ptr));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* AddressBook::InternalSerializeWithCachedSizesToArray(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:example.AddressBook)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .example.Person people = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_people_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessageToArray(1, this->_internal_people(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:example.AddressBook)
  return target;
}

size_t AddressBook::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:example.AddressBook)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .example.Person people = 1;
  total_size += 1UL * this->_internal_people_size();
  for (const auto& msg : this->people_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void AddressBook::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:example.AddressBook)
  GOOGLE_DCHECK_NE(&from, this);
  const AddressBook* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<AddressBook>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:example.AddressBook)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:example.AddressBook)
    MergeFrom(*source);
  }
}

void AddressBook::MergeFrom(const AddressBook& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:example.AddressBook)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  people_.MergeFrom(from.people_);
}

void AddressBook::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:example.AddressBook)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void AddressBook::CopyFrom(const AddressBook& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:example.AddressBook)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AddressBook::IsInitialized() const {
  if (!::PROTOBUF_NAMESPACE_ID::internal::AllAreInitialized(this->people())) return false;
  return true;
}

void AddressBook::InternalSwap(AddressBook* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  people_.InternalSwap(&other->people_);
}

::PROTOBUF_NAMESPACE_ID::Metadata AddressBook::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace example
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::example::Person_PhoneNumber* Arena::CreateMaybeMessage< ::example::Person_PhoneNumber >(Arena* arena) {
  return Arena::CreateInternal< ::example::Person_PhoneNumber >(arena);
}
template<> PROTOBUF_NOINLINE ::example::Person* Arena::CreateMaybeMessage< ::example::Person >(Arena* arena) {
  return Arena::CreateInternal< ::example::Person >(arena);
}
template<> PROTOBUF_NOINLINE ::example::AddressBook* Arena::CreateMaybeMessage< ::example::AddressBook >(Arena* arena) {
  return Arena::CreateInternal< ::example::AddressBook >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
