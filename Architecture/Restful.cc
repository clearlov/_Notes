/**
 * GET / POST / HEAD / PUT(insert) / PATCH(update) / DELETE / TRACE / CONNECT / OPTIONS
 */

class Resource
{
    public:
    Resource(URI uri);
    virtual Resource *get() = 0;
    virtual Resource *post(Request r) = 0;
    virtual Resource *put(Request r) = 0;
    virtual Resource *delete() = 0;
};