---
name: Feature
about: A sub-feature of an epic.
title: ''
labels: Feature
assignees: oroszpeter97

---

## Outcome / User value
What will be possible after this is complete? (Should be demoable in a build.)

## Requirements
### Functional
- <bullet list of behaviors>

### Non-functional (NFRs)
- Portability: <Windows/Linux/macOS expectations>
- Performance: <any budget/targets>
- Quality: <tests/logging/assertions expectations>

## Acceptance criteria (testable)
- [ ] Given <context>, when <action>, then <expected result>
- [ ] Given <context>, when <action>, then <expected result>
- [ ] Edge case: <case> behaves as <expected>

## Dependencies / Blockers
- Depends on: #<issue> / <thing>
- Blocked by: #<issue> / <thing>

## Definition of Ready (DoR)
- [ ] Acceptance criteria written
- [ ] Sized (S/M/L)
- [ ] Scoped small enough (≤ ~1 week solo) or split plan exists
- [ ] Dependencies identified

## Definition of Done (DoD)
- [ ] Implemented and merged
- [ ] CI green (build + lint/format + tests)
- [ ] Verified on target platforms (or documented limitation)
- [ ] Minimal docs updated if needed (README / ADR)
