#!/usr/bin/env bash
# Safe runner for whitelisted commands. Reads .command_whitelist in repo root.
set -eu
REPO_ROOT="$(cd "$(dirname "$0")/.." && pwd)"
WHITELIST_FILE="$REPO_ROOT/.command_whitelist"
if [ ! -f "$WHITELIST_FILE" ]; then
  echo "Whitelist file not found: $WHITELIST_FILE" >&2
  exit 1
fi

# Build allowed patterns into an array
mapfile -t ALLOWED < <(grep -v '^\s*#' "$WHITELIST_FILE" | sed '/^\s*$/d')
if [ ${#ALLOWED[@]} -eq 0 ]; then
  echo "No whitelisted commands found in $WHITELIST_FILE" >&2
  exit 1
fi

# Join args to a single command string
CMD="$*"
if [ -z "$CMD" ]; then
  echo "Usage: $0 <command and args>" >&2
  exit 2
fi

# Check exact or prefix match against ALLOWED
is_allowed=false
for allowed in "${ALLOWED[@]}"; do
  if [ "$CMD" = "$allowed" ] || [[ "$CMD" == "$allowed"* ]]; then
    is_allowed=true
    break
  fi
done

if [ "$is_allowed" != true ]; then
  echo "Command not whitelisted: $CMD" >&2
  exit 3
fi

# Execute the command
exec bash -lc "$CMD"
