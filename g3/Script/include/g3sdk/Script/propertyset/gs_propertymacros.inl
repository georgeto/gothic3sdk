template <typename PSP>
PSP &EntityPropertySet::AccessProperty()
{
    return *reinterpret_cast<typename PSP::PropertySetProperty *>(this);
}

template <typename PSP>
PSP const &EntityPropertySet::GetProperty() const
{
    return *reinterpret_cast<typename PSP::PropertySetProperty const *>(this);
}
